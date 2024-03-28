#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end) /*Empty tab*/
        return begin;
    if (begin > end)
        return end;
    int nb_elm = 0;
    int *tmp = begin;
    while (tmp != end)
    {
        tmp++;
        nb_elm++;
    }
    int *pos_pivot = begin + nb_elm / 2;
    int pivot = *(pos_pivot);
    if (elt < pivot)
    {
        return binary_search(begin, pos_pivot, elt);
    }
    else if (elt > pivot)
        return binary_search(pos_pivot + 1, end, elt);
    else
        return pos_pivot;
}
