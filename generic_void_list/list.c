#include "list.h"

#include <stdlib.h>
#include <string.h>

/*
** Insert a node containing `value` at the beginning of the list.
** Return `NULL` if an error occurred.
*/
struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = malloc(sizeof(struct list));
    void *data = malloc(data_size);
    if (!new || !data)
        return NULL;
    data = memcpy(data, value, data_size);
    new->data = data;
    new->next = list;
    return new;
}

/*
** Return the length of the list.
** Return `0` if the list is empty.
*/
size_t list_length(struct list *list)
{
    size_t len = 0;
    struct list *actual = list;
    while (actual)
    {
        len++;
        actual = actual->next;
    }
    return len;
}

/*
** Release the memory used by the list.
** Does nothing if `list` is `NULL`.
*/
void list_destroy(struct list *list)
{
    while (list)
    {
        struct list *next = list->next;
        free(list->data);
        free(list);
        list = next;
    }
}
