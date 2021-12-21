#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer() {}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::setCSD(int id)
{
    //printf("Csd Buffer - send CSD function > from ID %d\n", id);
    //storedID = id;
}
int CsdBuffer::getCSD()
{
    //printf("Csd Buffer - receive CSD function > To ID %d\n", id);
    int id = 120;
    return id;
}