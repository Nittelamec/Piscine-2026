#include "heap_sort.h"

size_t igauche(size_t i)
{
    return 2 * i + 1;
}

size_t idroite(size_t i)
{
    return 2 * i + 2;
}

void swap(int *array, size_t i, size_t j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return;
}

void percole(int *array, size_t size, size_t i)
{
    size_t iright = idroite(i);
    size_t ileft = igauche(i);
    if (ileft < size && iright < size)
    {
        int left_v = array[ileft];
        int right_v = array[iright];
        if (left_v > array[i] || right_v > array[i])
        {
            if (left_v > right_v)
            {
                swap(array, ileft, i);
                percole(array, size, ileft);
            }
            else
            {
                swap(array, iright, i);
                percole(array, size, iright);
            }
        }
    }
    else if (ileft < size)
    {
        int left_v = array[ileft];
        if (left_v > array[i])
        {
            swap(array, ileft, i);
            percole(array, size, ileft);
        }
    }
}

void heapify(int *array, size_t size)
{
    for (int i = size; i > 0; i--)
    {
        percole(array, size, i - 1);
    }
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);
    for (size_t k = 0; k < size; k++)
    {
        swap(array, 0, size - 1 - k);
        percole(array, size - 1 - k, 0);
    }
}
