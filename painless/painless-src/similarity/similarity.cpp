#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    test.store(120);
}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    printf("test : %d ", test.load());
    test = tmp;
    printf("-> %d\n", test.load());
}
int CsdBuffer::getCSD()
{

    int tmp = test;
    printf("getCSD : %d\n", tmp);
    return tmp;
}