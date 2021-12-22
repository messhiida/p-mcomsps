#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    my_csd = CSD();
    my_csd.nonZeroVars = 0;
    my_csd.data.clear();
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
