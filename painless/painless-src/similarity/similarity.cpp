#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer() {}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int tmp)
{
    test = tmp;
    printf("Csd Buffer - set CSD function > restarts %d\n", test);
}
int CsdBuffer::getCSD()
{
    //printf("Csd Buffer - receive CSD function > To ID %d\n", id);
    int id = 120;
    return id;
}