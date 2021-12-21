#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer() {}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
    printf("Csd Buffer - set CSD function > restarts %d / %d\n", tmp, test.load());
}
int CsdBuffer::getCSD()
{
    int tmp = test.load();
    printf("getCSD : %d\n", tmp);
    return tmp;
}