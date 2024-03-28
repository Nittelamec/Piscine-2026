#include "heap.h"

size_t igauche(size_t i)
{
    return 2 * i + 1;
}

size_t idroite(size_t i)
{
    return 2 * i + 2;
}

size_t iparent(size_t i)
{
    return (i - 1) / 2;
}

void swap(int *array, size_t i, size_t j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return;
}

void percole_haut(struct heap *heap, size_t i)
{
    if (i > 0)
    {
        int parent = iparent(i);
        if (heap->array[parent] < heap->array[i])
        {
            swap(heap->array, parent, i);
            percole_haut(heap, parent);
        }
    }
    return;
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->array = realloc(heap->array, 2 * heap->capacity * sizeof(int));
        heap->capacity = 2 * heap->capacity;
    }
    heap->array[heap->size] = val;
    percole_haut(heap, heap->size);
    heap->size += 1;
    return;
}
