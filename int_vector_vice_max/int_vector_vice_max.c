#include "int_vector_vice_max.h"

#include <stddef.h>

int array_vice_max(const int vec[], size_t size)
{
    int maxi;
    int maxi2;
    maxi = vec[0];
    maxi2 = vec[1];
    for (size_t i = 1; i < size; i++)
    {
        if (vec[i] > maxi2)
        {
            maxi2 = vec[i];
        }
        if (vec[i] > maxi)
        {
            maxi2 = maxi;
            maxi = vec[i];
        }
    }
    return maxi2;
}

int int_vector_vice_max(const struct int_vector vec)
{
    return array_vice_max(vec.data, vec.size);
}
