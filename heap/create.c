#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(struct heap));
    if (!heap)
        return NULL;
    else
    {
        heap->size = 0;
        heap->capacity = 8;
        heap->array = malloc(heap->capacity * sizeof(int));
        if (!heap->array)
            return NULL;
        return heap;
    }
}
