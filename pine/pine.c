#include <stdio.h>

int pine(unsigned int n)
{
    if (n < 3)
    {
        return 1;
    }
    else
    {
        int width = n - 1;
        int star = 1;
        for (unsigned int row = 0; row < n; row++)
        {
            for (int i = 0; i < width; i++)
            {
                putchar(' ');
            }
            for (int i = 0; i < star; i++)
            {
                putchar('*');
            }
            putchar('\n');
            width -= 1;
            star += 2;
        }
        for (unsigned int k = 0; k < n / 2; k++)
        {
            for (unsigned int i = 0; i < n - 1; i++)
            {
                putchar(' ');
            }
            putchar('*');
            putchar('\n');
        }
        return 0;
    }
}
