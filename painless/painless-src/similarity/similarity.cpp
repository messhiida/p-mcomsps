#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    test.store(100);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
}
int CsdBuffer::getCSD()
{
    int tmp = test;
    return tmp;
}