#include <stddef.h>

size_t element_count(int *begin, int *end)
{
    size_t i = 0;
    while (begin != end)
    {
        i++;
        begin += 1;
    }
    return i;
}
