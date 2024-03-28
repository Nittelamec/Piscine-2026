#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        unsigned long un_2 = 0;
        unsigned long un_1 = 1;
        unsigned long un = 0;
        unsigned long i = 1;
        while (i < n)
        {
            un = un_1 + un_2;
            un_2 = un_1;
            un_1 = un;
            i++;
        }
        return un;
    }
}
