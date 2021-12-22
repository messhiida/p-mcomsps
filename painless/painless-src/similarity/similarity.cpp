#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    storage.store(NULL);
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