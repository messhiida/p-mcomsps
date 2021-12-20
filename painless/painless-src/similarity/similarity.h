#include <stdio.h>
#include <vector>

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
