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
