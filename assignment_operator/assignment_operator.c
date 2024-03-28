#include <stddef.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    else
    {
        *a += *b;
        return;
    }
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    else
    {
        *a -= *b;
        return;
    }
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    else
    {
        *a *= *b;
        return;
    }
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
    {
        return 0;
    }
    else
    {
        int tmp = *a;
        *a /= *b;
        return tmp % *b;
    }
}
