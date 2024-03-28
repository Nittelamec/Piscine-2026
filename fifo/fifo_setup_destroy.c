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

struct fifo *fifo_init(void)
{
    struct fifo *new = malloc(sizeof(struct fifo));
    if (!new)
        return NULL;
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

void fifo_pop(struct fifo *fifo);

void fifo_clear(struct fifo *fifo)
{
    while (fifo->head != NULL)
    {
        fifo_pop(fifo);
    }
    return;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
    return;
}
