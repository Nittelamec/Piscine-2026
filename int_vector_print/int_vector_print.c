#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t len = vec.size;
    size_t i = 0;
    while (i < len)
    {
        if (i == len - 1)
        {
            printf("%d\n", vec.data[i]);
            i++;
        }
        else
        {
            printf("%d ", vec.data[i]);
            i++;
        }
    }
}
