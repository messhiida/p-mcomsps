#include "./similarity.h"
#include "../mapleCOMSPS/mapleCOMSPS/mtl/Heap.h"
#include "../mapleCOMSPS/mapleCOMSPS/core/Solver.h"

using namespace std;
/*
void Similarity::printStatusSim(int num)
{
    printf("test %d\n", num);
}

void Similarity::staticTestFunc()
{
    printf("static\n");
}

vector<csd_element> get_CSD()
{
    vector<csd_element> csd;

    csd[0].return csd;
}
*/
/*
    //UPDATE:: check restart status
    Heap<VarOrderLt> &order_heap = VSIDS ? order_heap_VSIDS : order_heap_CHB;
    printf("VSIDS: %d, restart:%d, #ofHeap %d, #ofPolairty %d", VSIDS, starts, order_heap.size(), polarity.size());
    if (order_heap.inHeap(100))
    {
        printf(", e.g. heap[100]=%d, polarity[100]=%d\n", order_heap[100], (int)polarity[100]);
    }
    else
    {
        printf("\n");
    }
    */
/*
vector<array<double, 3>> get_CSD(vector<double> scoreTable, vector<signed char> phases, CaDiCaL::ScoreSchedule scores)
{
    int var_size = (int)scoreTable.size();
    vector<array<double, 3>> csd(var_size); //csd[var] = {rank, phase, value},　不足分=下で定義されない分はzeroで埋められる
    double rank = 0.0;

    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        rank++;

        unsigned var_index = *it;
        double score = scoreTable[*it];
        if (score <= (double)CSD_SCORE_CRITERIA)
            break;

        assert(var_size);
        double varValue = pow(0.5, rank * CONSTANT_FOR_RANK_CALC / var_size); //この式はSSIの定義次第で変更すること
        double polarity = phases[var_index];

        array<double, 3> element = {rank, polarity, varValue};
        csd[var_index] = element;
    }

    return csd;
}
*/