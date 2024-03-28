#include "heap.h"

void __print_heap(const struct heap *heap, size_t i)
{
    if (i < heap->size)
    {
        if (i > 0)
            putchar(' ');
        printf("%d", heap->array[i]);
        __print_heap(heap, 2 * i + 1);
        __print_heap(heap, 2 * i + 2);
    }
}

void print_heap(const struct heap *heap)
{
    __print_heap(heap, 0);
    putchar('\n');
}
