#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    if (list->size != 0)
    {
        int res;
        size_t i = 0;
        struct dlist_item *actual = list->head;
        while (i != index && actual)
        {
            actual = actual->next;
            i++;
        }
        if (i != index)
            res = -1;
        else
            res = actual->data;
        return res;
    }
    else
        return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index == 0)
        return dlist_push_front(list, element);
    else if (index == list->size)
        return dlist_push_back(list, element);
    else if (index > list->size || element < 0)
        return -1;
    else
    {
        struct dlist_item *actual = list->head;
        size_t i = 0;
        while (i != index && actual)
        {
            actual = actual->next;
            i++;
        }
        struct dlist_item *new = malloc(sizeof(struct dlist));
        if (!new)
            return -1;
        new->data = element;
        new->next = actual;
        new->prev = actual->prev;
        actual->prev->next = new;
        actual->prev = new;
        list->size += 1;
        return 1;
    }
}

int dlist_find(const struct dlist *list, int element)
{
    if (list->size != 0)
    {
        struct dlist_item *actual = list->head;
        size_t i = 0;
        while (actual && actual->data != element)
        {
            actual = actual->next;
            i++;
        }
        if (!actual)
            return -1;
        else
            return i;
    }
    else
        return -1;
}

void __dlist_remove_at(struct dlist *list, size_t index)
{
    if (list->size > 0)
    {
        size_t size = list->size;
        struct dlist_item *hook;
        if (index == 0)
        {
            hook = list->head->next;
            free(list->head);
            list->head = hook;
            list->head->prev = NULL;
        }
        else if (index == size - 1)
        {
            hook = list->tail->prev;
            free(list->tail);
            list->tail = hook;
            list->tail->next = NULL;
        }
    }
    else
        return;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    int res = -1;
    if (list->size > 0 && index < list->size)
    {
        if (list->size == 1)
        {
            res = list->head->data;
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else if (index == 0)
        {
            res = list->head->data;
            __dlist_remove_at(list, index);
        }
        else if (index == list->size - 1)
        {
            res = list->tail->data;
            __dlist_remove_at(list, index);
        }
        else
        {
            struct dlist_item *actual = list->head;
            size_t i = 0;
            while (i != index)
            {
                actual = actual->next;
                i++;
            }
            res = actual->data;
            actual->prev->next = actual->next;
            actual->next->prev = actual->prev;
            free(actual);
        }
        list->size -= 1;
        return res;
    }
    else
        return -1;
}

void dlist_clear(struct dlist *list)
{
    if (list->size > 0)
    {
        int is_rem = 0;
        while (is_rem != -1)
        {
            is_rem = dlist_remove_at(list, 0);
        }
        list->size = 0;
    }
}
