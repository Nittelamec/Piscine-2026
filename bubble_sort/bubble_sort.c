#include <stddef.h>

void swap_index(int t[], size_t i, size_t j)
{
    int tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
    return;
}
void bubble_sort(int t[], size_t size)
{
    if (size == 0)
    {
        return;
    }
    int is_permut = 0;
    while (is_permut == 0)
    {
        is_permut = 1;
        for (size_t i = 0; i < size - 1; i++)
        {
            if (t[i] > t[i + 1])
            {
                swap_index(t, i, i + 1);
                is_permut = 0;
            }
        }
    }
}
int t[] = {
    5,
    7,
    5,
    8,
}
