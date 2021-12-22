#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    storage.store(NULL);
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
