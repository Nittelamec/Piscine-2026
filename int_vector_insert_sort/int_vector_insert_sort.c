#include <stddef.h>

#define INT_VECTOR_LENGTH 64

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (size_t i = 1; i < vec.size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (vec.data[i] < vec.data[j])
            {
                vec = swap(vec, i, j);
            }
        }
    }
    return vec;
}
