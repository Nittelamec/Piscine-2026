#include "heap.h"

void percole(struct heap *heap, size_t i)
{
    size_t iright = idroite(i);
    size_t ileft = igauche(i);
    if (ileft < heap->size && iright < heap->size)
    {
        int left_v = heap->array[ileft];
        int right_v = heap->array[iright];
        if (left_v > heap->array[i] || right_v > heap->array[i])
        {
            if (left_v > right_v)
            {
                swap(heap->array, ileft, i);
                percole(heap, ileft);
            }
            else
            {
                swap(heap->array, iright, i);
                percole(heap, iright);
            }
        }
    }
    else if (ileft < heap->size)
    {
        int left_v = heap->array[ileft];
        if (left_v > heap->array[i])
        {
            swap(heap->array, ileft, i);
            percole(heap, ileft);
        }
    }
}

int pop(struct heap *heap)
{
    assert(heap->size != 0 && "Assertion failed");
    int hmax = heap->array[0];
    swap(heap->array, 0, heap->size - 1);
    heap->size -= 1;
    if (heap->size < (heap->capacity / 2))
    {
        if (heap->capacity > 8)
        {
            heap->array =
                realloc(heap->array, (heap->capacity / 2) * sizeof(int));
            heap->capacity /= 2;
        }
    }
    percole(heap, 0);
    return hmax;
}
