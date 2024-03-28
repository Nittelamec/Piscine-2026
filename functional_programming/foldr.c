#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int res = 0;
    for (size_t i = len; i > 0; i--)
    {
        res = func(array[i - 1], res);
    }
    return res;
}
