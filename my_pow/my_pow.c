#include <assert.h>

int my_pow(int x, int n)
{
    assert(n >= 0);
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    else
    {
        if (n % 2 == 0)
        {
            return my_pow(x * x, n / 2);
        }
        else
        {
            return x * my_pow(x * x, (n - 1) / 2);
        }
    }
}
