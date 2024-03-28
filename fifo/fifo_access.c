#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct fifo
{
    struct list *head;
    struct list *tail;
    size_t size;
};

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new_tail = malloc(sizeof(struct list));
    if (!new_tail)
        return;
    new_tail->data = elt;
    new_tail->next = NULL;
    if (fifo->tail == NULL)
    {
        fifo->tail = new_tail;
        fifo->head = new_tail;
        fifo->size += 1;
    }
    else
    {
        fifo->tail->next = new_tail;
        fifo->tail = new_tail;
        fifo->size += 1;
    }
    return;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    struct list *tmp = fifo->head->next;
    free(fifo->head);
    fifo->head = tmp;
    fifo->size -= 1;
    return;
}

void fifo_print(const struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    struct list *actual = fifo->head;
    while (actual != NULL)
    {
        printf("%d\n", actual->data);
        actual = actual->next;
    }
    return;
}
