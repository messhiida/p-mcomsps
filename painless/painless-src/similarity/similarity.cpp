#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    //storage.store(100);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    storage = tmp;
}
int CsdBuffer::catchCSD()
{
    int tmp = storage;
    return tmp;
}