#pragma once

#include <stdio.h>
#include <vector>
#include <atomic>
#include <algorithm>

using namespace std;

#define CONSTANT_FOR_RANK_CALC 10.0 // Rank計算用定数
#define CSD_SET_CRITERIA 1          //これ未満のactivityの値はSkipする
#define CHANGE_RESTART_FREQ 100     // CHANGE_RESTART_FREQ回のrestartに1回実行
#define CHANGE_RATIO 0.1            // CHANGE_RATIO x nVars()の変数分を変更
#define CHANGE_VAR_BUMP_TIMES 10000 // varBumpActivity CHANGE_VAR_BUMP_TIMES回分実行
#define MAX_PARALLEL 48             //並列数を指定。適切に並列数を選択すること
#define ALPHA_TO_JUDGE_SSI 2        //標準偏差の閾値
#define LIMIT_SAVING_SSI 500        // SSI databaseの保存上限
#define CHANGE_INTERVAL 0           //この回数以上間が空いていないとChange searchさせない
#define GE_diversification true
#define verso_diversification true

struct csd_element
{
    int rank;
    bool phase;
    double value;
};

struct CSD
{
    int nonZeroVars;
    vector<csd_element> data;
};

class CsdBuffer
{
public:
    CsdBuffer();  /// Constructor.
    ~CsdBuffer(); /// Destructor.
    void setCSD(CSD);
    CSD catchCSD();
    void recordCSD(CSD, int);
    vector<CSD> readRecordedCSD();

protected:
    CSD my_csd;
    vector<CSD> csdStorage;
};

enum similarityLevel
{
    high,
    normal,
    low
};
