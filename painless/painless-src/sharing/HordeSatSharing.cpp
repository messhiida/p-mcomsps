// -----------------------------------------------------------------------------
// Copyright (C) 2017  Ludovic LE FRIOUX
//
// This file is part of PaInleSS.
//
// PaInleSS is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
// -----------------------------------------------------------------------------

#include "../clauses/ClauseManager.h"
#include "../sharing/HordeSatSharing.h"
#include "../solvers/SolverFactory.h"
#include "../utils/Logger.h"
#include "../utils/Parameters.h"

#include "../similarity/similarity.h"

HordeSatSharing::HordeSatSharing()
{
   this->literalPerRound = Parameters::getIntParam("shr-lit", 1500);
   this->initPhase = true;
   // number of round corresponding to 5% of the 5000s timeout
   this->roundBeforeIncrease = 250000000 / Parameters::getIntParam("shr-sleep", 500000);
}

HordeSatSharing::~HordeSatSharing()
{
   for (auto pair : this->databases)
   {
      delete pair.second;
   }
}

void HordeSatSharing::doSharing(int idSharer, const vector<SolverInterface *> &from,
                                const vector<SolverInterface *> &to)
{
   static unsigned int round = 1;

   //UPDATE:: shared CSD loop
   vector<clock_t> times;
   times.push_back(clock());
   vector<int> tmp_sharedCSD;
   for (size_t i = 0; i < from.size(); i++)
   {
      if (from[i]->id > (MAX_PARALLEL - 4 + 1))
         continue; //Reducer用のものはskip

      times.push_back(clock());
      CSD tmp_csd = from[i]->loadSharedCSD();
      times.push_back(clock());
      for (size_t j = 0; j < to.size(); j++)
      {
         //from, To ともにChange searchさせないために、[0]はすべてを受けるが、[7]は何も受けない調整を実施
         //nonZeroVars == 0は、SharerやReducerのものが該当。これは無視
         if (from[i]->id > to[j]->id && tmp_csd.nonZeroVars != 0)
         {
            times.push_back(clock());
            to[j]->registerSharedCSD(tmp_csd, from[i]->id);
            times.push_back(clock());
         }
      }
   }

   times.push_back(clock());
   printf("[Sharer %d]: ", idSharer);
   double prevTime = 0;
   for (size_t i = 0; i < times.size(); i++)
   {
      double t = (double)times[i];
      printf("%lf, ", (t - prevTime) / CLOCKS_PER_SEC);
      prevTime = t;
   }
   printf("\n");

   for (size_t i = 0; i < from.size(); i++)
   {
      int used, usedPercent, selectCount;
      int id = from[i]->id;

      if (!this->databases.count(id))
      {
         this->databases[id] = new ClauseDatabase();
      }

      tmp.clear();

      from[i]->getLearnedClauses(tmp);

      stats.receivedClauses += tmp.size();

      for (size_t k = 0; k < tmp.size(); k++)
      {
         this->databases[id]->addClause(tmp[k]);
      }

      tmp.clear();

      used = this->databases[id]->giveSelection(tmp, literalPerRound, &selectCount);
      usedPercent = (100 * used) / literalPerRound;

      stats.sharedClauses += tmp.size();

      if (usedPercent < 75 && !this->initPhase)
      {
         from[i]->increaseClauseProduction();
         log(1, "Sharer %d production increase for solver %d.\n", idSharer,
             from[i]->id);
      }
      else if (usedPercent > 98)
      {
         from[i]->decreaseClauseProduction();
         log(1, "Sharer %d production decrease for solver %d.\n", idSharer,
             from[i]->id);
      }

      if (selectCount > 0)
      {
         log(1, "Sharer %d filled %d%% of its buffer %.2f\n", idSharer,
             usedPercent, used / (float)selectCount);
         this->initPhase = false;
      }
      if (round >= this->roundBeforeIncrease)
      {
         this->initPhase = false;
      }

      for (size_t j = 0; j < to.size(); j++)
      {
         if (from[i]->id != to[j]->id)
         {
            for (size_t k = 0; k < tmp.size(); k++)
            {
               ClauseManager::increaseClause(tmp[k], 1);
            }
            to[j]->addLearnedClauses(tmp);
         }
      }

      for (size_t k = 0; k < tmp.size(); k++)
      {
         ClauseManager::releaseClause(tmp[k]);
      }
   }
   round++;
}

SharingStatistics
HordeSatSharing::getStatistics()
{
   return stats;
}
