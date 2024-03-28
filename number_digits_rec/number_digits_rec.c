#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

unsigned int count_numbers(unsigned int n, unsigned int accu)
{
    if (n == 0)
    {
        return accu;
    }
    else
    {
        return count_numbers(n / 10, accu + 1);
    }
}

unsigned int number_digits_rec(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return count_numbers(n, 0);
    }
}
