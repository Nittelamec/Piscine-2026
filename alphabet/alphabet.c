#include <stdio.h>

int main(void)
{
    int min = 97;
    int max = 122;
    int spc = 32;
    int nwl = 10;
    for (int i = min; i <= max; i++)
    {
        if (i == max)
        {
            putchar(i);
            putchar(nwl);
        }
        else
        {
            putchar(i);
            putchar(spc);
        }
    }
    return 0;
}
