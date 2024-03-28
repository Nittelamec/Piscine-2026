#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (list && list->size > 0 && offset != 0)
    {
        int rem = 1;
        if (offset > 0)
        {
            offset %= list->size;
            for (int i = 0; i < offset; i++)
            {
                rem = dlist_remove_at(list, list->size - 1);
                dlist_push_front(list, rem);
            }
        }
        else
        {
            offset *= -1;
            offset %= list->size;
            for (int i = 0; i < offset; i++)
            {
                rem = dlist_remove_at(list, 0);
                dlist_push_back(list, rem);
            }
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (list && element >= 0)
    {
        if (list->size == 0)
            return dlist_push_front(list, element);
        else
        {
            size_t index = 0;
            struct dlist_item *actual = list->head;
            while (actual && element > actual->data)
            {
                actual = actual->next;
                index++;
            }
            if (!actual)
                return dlist_push_back(list, element);
            else
                return dlist_insert_at(list, element, index);
        }
    }
    else
        return -1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (list && list->size > 0 && element >= 0)
    {
        size_t index = 0;
        struct dlist_item *actual = list->head;
        while (actual && actual->data != element)
        {
            index++;
            actual = actual->next;
        }
        if (!actual)
            return 0;
        int rem = dlist_remove_at(list, index);
        return (rem != -1) ? 1 : 0;
    }
    else
        return -1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (list)
    {
        struct dlist *new_list = dlist_init();
        if (!new_list)
            return NULL;
        if (list->size == 0)
            return new_list;
        for (size_t i = 0; i < list->size; i++)
        {
            int val = dlist_get(list, i);
            dlist_push_back(new_list, val);
        }
        return new_list;
    }
    else
        return NULL;
}
