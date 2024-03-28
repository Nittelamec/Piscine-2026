#include "insertion_sort.h"

#include <stdlib.h>

void insertion_sort(void **array, f_cmp comp)
{
    if (!array || !*array)
        return;
    for (size_t i = 1; array[i] != NULL; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (comp(array[i], array[j]) < 0)
            {
                void *tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
}
