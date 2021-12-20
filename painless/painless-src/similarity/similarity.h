#include <stdio.h>
#include <vector>

#define CHANGE_RESTART_FREQ 100     //CHANGE_RESTART_FREQ回のrestartに1回実行
#define CHANGE_RATIO 0.1            //CHANGE_RATIO x nVars()の変数分を変更
#define CHANGE_VAR_BUMP_TIMES 10000 //varBumpActivity CHANGE_VAR_BUMP_TIMES回分実行

class Similarity
{
private:
    int test = 0;

public:
    int id;
    Similarity(){};
    ~Similarity(){};
    void printStatusSim(int num);
    static void staticTestFunc();
};

struct csd_element
{
    int rank;
    bool polarity;
    double varValue;
};
