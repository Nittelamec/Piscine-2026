#include "dlist.h"

void swap(struct dlist_item *i, struct dlist_item *j)
{
    int tmp = i->data;
    i->data = j->data;
    j->data = tmp;
    return;
}

void dlist_bubble_sort(struct dlist *list)
{
    if (list->size <= 1)
    {
        return;
    }
    int is_permut = 0;
    struct dlist_item *actual;
    size_t index;
    while (is_permut == 0)
    {
        is_permut = 1;
        index = 0;
        actual = list->head;
        while (index < list->size - 1)
        {
            if (actual->data > actual->next->data)
            {
                swap(actual, actual->next);
                actual = actual->next;
                is_permut = 0;
                index++;
            }
            else
            {
                index++;
                actual = actual->next;
            }
        }
    }
}

void dlist_sort(struct dlist *list)
{
    if (list)
        dlist_bubble_sort(list);
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (list1)
    {
        dlist_concat(list1, list2);
        dlist_sort(list1);
    }
}
