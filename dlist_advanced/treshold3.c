#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (list && list->size > 0)
    {
        struct dlist_item *actual = list->head;
        while (actual)
        {
            actual->data *= actual->data;
            actual = actual->next;
        }
    }
}

void dlist_reverse(struct dlist *list)
{
    if (list->size > 1)
    {
        int rem = 1;
        int ins = 1;
        for (size_t i = list->size; i > 1; i--)
        {
            if (rem && ins)
            {
                int val = dlist_get(list, list->size - 1);
                rem = dlist_remove_at(list, list->size - 1);
                list->size += 1;
                ins = dlist_insert_at(list, val, list->size - i);
                list->size -= 1;
            }
        }
        list->tail->next = NULL;
        list->head->prev = NULL;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index < list->size)
    {
        struct dlist *snd_half = dlist_init();
        if (!snd_half)
            return NULL;
        if (list->size == 0)
            return snd_half;
        if (index == list->size - 1)
        {
            dlist_push_front(snd_half, list->tail->data);
            dlist_remove_at(list, list->size - 1);
            list->tail->next = NULL;
            return snd_half;
        }
        size_t pos = 0;
        struct dlist_item *actual = list->head;
        while (pos != index)
        {
            actual = actual->next;
            pos++;
        }
        int rem = 1;
        int ins = 1;
        for (size_t i = list->size; i > pos && rem != -1 && ins != -1; i--)
        {
            int val = dlist_get(list, i - 1);
            rem = dlist_remove_at(list, i - 1);
            ins = dlist_push_front(snd_half, val);
        }
        return snd_half;
    }
    else
        return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2)
    {
        int rem;
        while (list2->size != 0)
        {
            rem = dlist_remove_at(list2, 0);
            dlist_push_back(list1, rem);
        }
    }
}
