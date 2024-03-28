#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;
    if (width % 2 == 0)
    {
        width = width + 1;
    }
    int row = (width + 1) / 2;
    for (int i = 0; i < row; i++)
    {
        if (i == 0 || i == row - 1)
        {
            for (int k = 0; k < width; k++)
            {
                putchar('*');
            }
            putchar('\n');
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                {
                    putchar('*');
                }
                else if (j == width - 1)
                {
                    putchar('*');
                    putchar('\n');
                }
                else
                {
                    putchar(' ');
                }
            }
        }
    }
}
