#include <stdio.h>
#include <vector>

#define RESTART_FREQ 100
#define CHANGE_RATIO 0.1

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
