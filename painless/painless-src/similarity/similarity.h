#pragma once

#include <stdio.h>
#include <vector>
#include <atomic>

using namespace std;

#define CONSTANT_FOR_RANK_CALC 10.0
#define CSD_SET_CRITERIA 1
#define CHANGE_RESTART_FREQ 100     //CHANGE_RESTART_FREQ回のrestartに1回実行
#define CHANGE_RATIO 0.1            //CHANGE_RATIO x nVars()の変数分を変更
#define CHANGE_VAR_BUMP_TIMES 10000 //varBumpActivity CHANGE_VAR_BUMP_TIMES回分実行

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
    /// Constructor.
    CsdBuffer();
    /// Destructor.
    ~CsdBuffer();

    void setCSD(int);
    int getCSD();

protected:
    CSD csd;
    atomic<int> test;
};
