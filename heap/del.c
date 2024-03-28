#include "heap.h"

void delete_heap(struct heap *heap)
{
    free(heap->array);
    heap->array = NULL;
    free(heap);
    heap = NULL;
    return;
}
