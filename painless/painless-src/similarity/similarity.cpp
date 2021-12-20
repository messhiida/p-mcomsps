#include "./similarity.h"
#include "../mapleCOMSPS/mapleCOMSPS/mtl/Heap.h"
#include "../mapleCOMSPS/mapleCOMSPS/core/Solver.h"

//using namespace std;
namespace MapleCOMSPS
{

    void Solver::changeSearchActivity()
    {
        int n = order_heap_VSIDS.size();
        int change_n = (double)n * CHANGE_RATIO;
        //printf("[%d restarts] OrderHeap %d, Change %d in Total nVar %d\n", starts, n, change_n, nVars());
        for (int i = n; i >= change_n; i--) //orderHeapのrankが低い下から順にVarを取得していく
        {
            assert(i >= 0);
            Var v = order_heap_VSIDS[i];
            varBumpActivity(v, CHANGE_VAR_BUMP_TIMES);
            //printf("order %d: var %d, activity %lf, order[v] %d, rank[v] %d\n", i, v, activity_VSIDS[v], order_heap_VSIDS[v], order_heap_VSIDS.rank(v));
        }
    }

    CSD Solver::getCSD()
    {
        CSD csd;
        int var_size = nVars();
        csd.nonZeroVars = 0;
        csd.data.resize(var_size);

        for (int i = 0; i < var_size; i++)
        {
            double score = activity_VSIDS[i];
            if (!order_heap_VSIDS.inHeap(i) || score < CSD_SET_CRITERIA)
                continue;

            csd_element e;
            e.rank = order_heap_VSIDS.rank(i) + 1; //orderHeapの最上位は0始まりの為、+1で補正
            e.phase = polarity[i];
            e.value = pow(0.5, e.rank * CONSTANT_FOR_RANK_CALC / var_size);
            csd.data[i] = e;

            if (score > 0)
                csd.nonZeroVars++;
        }
        return csd;
    }
}
