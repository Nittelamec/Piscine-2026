#include "is_set.h"

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int mask = 1 << (n - 1);
    unsigned int res = value & mask;

    return (res == 0) ? 0 : 1;
}
