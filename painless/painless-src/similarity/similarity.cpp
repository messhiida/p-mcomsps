#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    test.store(120);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
}
int CsdBuffer::getCSD()
{
    int tmp = test;
    printf("getCSD : %d\n", tmp);
    return tmp;
}