#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector
{
    // The number of elements in the vector
    size_t size;
    // The maximum number of elements in the vector
    size_t capacity;
    // The elements themselves
    int *data;
};

/*
** Initialize the vector with `n` capacity.
** Returns `NULL` if an error occured.
*/
struct vector *vector_init(size_t n)
{
    struct vector *new = malloc(sizeof(struct vector));
    int *array = malloc(n * sizeof(int));
    if (!array || !new)
        return NULL;
    new->data = array;
    new->size = 0;
    new->capacity = n;
    return new;
}

/*
** Release the memory used by the vector.
** Does nothing if `v` is `NULL`.
*/
void vector_destroy(struct vector *v)
{
    if (v && v->data)
    {
        free(v->data);
        free(v);
    }
}

/*
** Resize the vector to `n` capacity.
** Returns `NULL` if an error occured.
*/
struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n < v->capacity)
    {
        v->data = realloc(v->data, n * sizeof(int));
        v->size = n;
        v->capacity = n;
        return v;
    }
    else if (n > v->capacity)
    {
        v->data = realloc(v->data, n * sizeof(int));
        v->capacity = n;
        return v;
    }
    else
        return v;
}

/*
** Append an element to the end of the vector. Expand the vector if needed.
** Returns `NULL` if an error occured.
*/
struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;
    if (v->size == v->capacity)
        v = vector_resize(v, v->capacity * 2);
    if (!v)
        return NULL;
    v->data[v->size] = elt;
    v->size += 1;
    return v;
}

/*
** Display the vector contents on `stdout`.
** Displays `\n` if `v` is `NULL`.
*/
void vector_print(const struct vector *v)
{
    if (v)
    {
        if (v->size == 0)
            printf("\n");
        else
        {
            for (size_t i = 0; i < v->size; i++)
            {
                if (i == v->size - 1)
                    printf("%d\n", v->data[i]);
                else
                    printf("%d,", v->data[i]);
            }
        }
    }
    else
        printf("\n");
}

/*
** Remove all the elements of the vector, and resize it to `n` capacity.
** Returns `NULL` if an error occured.
*/
struct vector *vector_reset(struct vector *v, size_t n)
{
    v = vector_resize(v, n);
    if (!v)
        return NULL;
    v->size = 0;
    return v;
}

/*
** Insert `n` at the index `i`. Expand the vector if needed.
*/
struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;
    else if (i == v->size)
        return vector_append(v, elt);
    else
    {
        if (v->size == v->capacity)
        {
            v = vector_resize(v, v->capacity * 2);
            if (!v)
                return NULL;
        }
        for (size_t j = v->size; j > i; j--)
            v->data[j] = v->data[j - 1];
        v->data[i] = elt;
        v->size += 1;
    }
    return v;
}

/*
** Remove an element at the index 'i'.
*/
struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v)
        return NULL;
    if (i >= v->size)
        return NULL;
    for (size_t j = i; j < v->size - 1; j++)
        v->data[j] = v->data[j + 1];
    v->size -= 1;
    if (v->size < v->capacity / 2)
        v->capacity /= 2;
    return v;
}
