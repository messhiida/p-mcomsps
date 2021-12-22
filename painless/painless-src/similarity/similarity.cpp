#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    test.store(100);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    printf("b: %d -> ", tmp);
    test = tmp;
    printf("%d\n", tmp);
}
int CsdBuffer::getCSD()
{
    int tmp = test;
    return tmp;
}