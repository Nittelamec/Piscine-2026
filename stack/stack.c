#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *top = malloc(sizeof(struct stack));
    if (!top)
        return NULL;
    top->data = e;
    if (!s)
    {
        top->next = NULL;
        return top;
    }
    top->next = s;
    return top;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
        return NULL;
    struct stack *hook = s->next;
    free(s);
    return hook;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
