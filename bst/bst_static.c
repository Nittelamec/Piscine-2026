#include "bst_static.h"

#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct value **data = malloc(capacity * sizeof(struct value *));
    struct bst *new = malloc(sizeof(struct bst));
    if (!new || !data)
        return NULL;
    for (size_t i = 0; i < capacity; i++)
    {
        data[i] = NULL;
    }
    new->data = data;
    new->capacity = capacity;
    new->size = 0;
    return new;
}

void __add(struct bst *tree, int value, size_t i)
{
    if (i >= tree->capacity)
    {
        struct value *node = malloc(sizeof(struct value));
        tree->data =
            realloc(tree->data, 2 * tree->capacity * sizeof(struct val *));
        if (tree->data && node)
        {
            for (size_t i = tree->capacity; i < 2 * tree->capacity; i++)
                tree->data[i] = NULL;
            tree->size += 1;
            tree->capacity *= 2;
            node->val = value;
            tree->data[i] = node;
        }
    }
    else if (tree->data[i] == NULL)
    {
        struct value *node = malloc(sizeof(struct value));
        if (node)
        {
            tree->size += 1;
            node->val = value;
            tree->data[i] = node;
        }
    }
    else if (value < tree->data[i]->val)
        __add(tree, value, 2 * i + 1);
    else if (value > tree->data[i]->val)
        __add(tree, value, 2 * i + 2);
}

void add(struct bst *tree, int value)
{
    if (!tree)
    {
        struct bst *new = init(8);
        struct value *node = malloc(sizeof(struct value));
        if (new &&node)
        {
            tree->size += 1;
            node->val = value;
            new->data[0] = node;
            tree = new;
        }
    }
    else if (tree->size == 0)
    {
        struct value *node = malloc(sizeof(struct value));
        if (node)
        {
            tree->size += 1;
            node->val = value;
            tree->data[0] = node;
        }
    }
    else
    {
        __add(tree, value, 0);
    }
}

int __search(struct bst *tree, int value, size_t i)
{
    if (tree->data[i] == NULL || i >= tree->capacity)
        // value is not here bc i is invalid or there is no node i.e NULL
        return -1;
    if (value < tree->data[i]->val)
        return __search(tree, value, 2 * i + 1);
    else if (value > tree->data[i]->val)
        return __search(tree, value, 2 * i + 2);
    else
        return i;
}

int search(struct bst *tree, int value)
{
    if (!tree || tree->size == 0)
        return -1;
    return __search(tree, value, 0);
}

void bst_free(struct bst *tree)
{
    if (tree)
    {
        for (size_t i = 0; i < tree->capacity; i++)
            free(tree->data[i]);
        free(tree->data);
        free(tree);
    }
}
