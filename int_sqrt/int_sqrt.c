#include <stdio.h>

int int_sqrt(int n)
{
    int res = 0;
    if (n < 0)
        res = -1;
    else
    {
        while (res * res < n)
            res++;

        if (res * res > n)
            res -= 1;
    }
    return res;
}
