#include "./similarity.h"

using namespace std;

CsdBuffer::CsdBuffer() {}
CsdBuffer::~CsdBuffer() {}

void CsdBuffer::sendCSD(int id)
{
    printf("Csd Buffer - send CSD function > from ID %d\n", id);
    storedID = id;
}
void CsdBuffer::receiveCSD()
{
    int id = 0;
    printf("Csd Buffer - receive CSD function > To ID %d\n", id);
}