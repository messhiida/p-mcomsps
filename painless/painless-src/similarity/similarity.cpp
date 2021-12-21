#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer() {}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
}
int CsdBuffer::getCSD()
{
    int tmp = test.load();
    printf("getCSD : %d\n", tmp);
    return tmp;
}