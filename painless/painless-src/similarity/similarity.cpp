#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    my_csd = CSD();
    my_csd.nonZeroVars = 0;
    my_csd.data.clear();
    csdStorage.resize(MAX_PARALLEL + 2);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(CSD input)
{
    my_csd = input;
}
CSD CsdBuffer::catchCSD()
{
    return my_csd;
}
void CsdBuffer::recordCSD(CSD input, int id)
{
    csdStorage[id] = input;
}
vector<CSD> CsdBuffer::readRecordedCSD()
{
    return csdStorage;
}

double _average(vector<double> v)
{
    double sum = 0;
    for (double s : v)
        sum += s;
    return sum / (double)v.size();
}

double _standardDeviation(vector<double> v)
{
    double sum2 = 0;
    for (double s : v)
        sum2 += s * s;
    double ave = _average(v);
    return sqrt(sum2 / (double)v.size() - ave * ave);
}

void _save_SSI(double ssi, vector<double> &history)
{
    history.push_back(ssi);
    if ((int)history.size() > LIMIT_SAVING_SSI)
        history.erase(history.begin());
}
