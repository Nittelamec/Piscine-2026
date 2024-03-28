#ifndef HEAP_SORT_H
#define HEAP_SORT_H

// libraries nedded
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t igauche(size_t i);
size_t idroite(size_t i);
void swap(int *array, size_t i, size_t j);
void heap_sort(int *array, size_t size);

#endif /* !HEAP_SORT_H */
