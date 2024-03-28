#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    char *mem = malloc(n * size);
    if (!mem)
    {
        return NULL;
    }
    for (size_t i = 0; i < n * size; i++)
    {
        mem[i] = 0;
    }
    return mem;
}
