#include "int_vector_max.h"

#include <stddef.h>

int int_vector_max(const struct int_vector vec)
{
    size_t len = vec.size;
    int max = vec.data[0];
    size_t i = 0;
    while (i < len)
    {
        if (max < vec.data[i])
        {
            max = vec.data[i];
        }
        i++;
    }
    return max;
}
