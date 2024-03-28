#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;
    new->data = element;
    new->prev = NULL;
    if (list->size == 0)
    {
        new->next = NULL;
        list->tail = new;
        list->head = new;
        list->size += 1;
    }
    else
    {
        list->head->prev = new;
        struct dlist_item *tmp = list->head;
        list->head = new;
        new->next = tmp;
        list->size += 1;
    }
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list && list->size > 0)
    {
        struct dlist_item *actual = list->head;
        while (actual)
        {
            printf("%d\n", actual->data);
            actual = actual->next;
        }
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;
    new->data = element;
    new->next = NULL;
    if (list->size == 0)
    {
        new->prev = NULL;
        list->tail = new;
        list->head = new;
        list->size += 1;
    }
    else
    {
        list->tail->next = new;
        struct dlist_item *tmp = list->tail;
        list->tail = new;
        new->prev = tmp;
        list->size += 1;
    }
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
