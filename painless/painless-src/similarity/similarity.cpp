#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer()
{
    test.store(120);
    printf("constructed\n");
}
CsdBuffer::~CsdBuffer()
{
    printf("deconstructed\n");
}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
}
int CsdBuffer::getCSD()
{
    int tmp = test.load();
    //printf("getCSD : %d\n", tmp);
    return tmp;
}