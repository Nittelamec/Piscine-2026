#include <stddef.h>

void pointer_swap(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
