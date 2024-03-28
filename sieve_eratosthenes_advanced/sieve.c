#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    else
    {
        int *ptab = calloc(n, 4);
        int nbp = 0;
        for (int i = 2; i * i < n; i++)
        {
            for (int j = i * i; j < n; j += i)
            {
                if (j % i == 0)
                    ptab[j - 2] = 1;
            }
        }
        for (int i = 0; i < n - 2; i++)
        {
            if (ptab[i] == 0)
                nbp++;
        }
        printf("%d\n", nbp);
        free(ptab);
    }
}
