#include "bst.h"

#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    if (!node)
        return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
    {
        struct bst_node *new_node = create_node(value);
        return new_node;
    }
    if (value == tree->data)
        return tree;
    else if (value < tree->data)
    {
        tree->left = add_node(tree->left, value);
        return tree;
    }
    else
    {
        tree->right = add_node(tree->right, value);
        return tree;
    }
}

int max_bst(struct bst_node *tree)
{
    if (tree->right == NULL)
    {
        int max = tree->data;
        return max;
    }
    else
    {
        return max_bst(tree->right);
    }
}

struct bst_node *__delete_node(struct bst_node *tree, int value, int *id)
{
    if (tree)
    {
        if (value < tree->data)
            tree->left = __delete_node(tree->left, value, id);
        else if (value > tree->data)
            tree->right = __delete_node(tree->right, value, id);
        else
        {
            *id += 1;
            if (tree->left == NULL)
            {
                struct bst_node *tmp = tree;
                tree = tree->right;
                free(tmp);
            }
            else if (tree->right == NULL)
            {
                struct bst_node *tmp = tree;
                tree = tree->left;
                free(tmp);
            }
            else
            {
                int max_left = max_bst(tree->left);
                tree->data = max_left;
                tree->left = __delete_node(tree->left, max_left, id);
            }
        }
        return tree;
    }
    return NULL;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    int i = 0;
    int *id = &i;
    tree = __delete_node(tree, value, id);
    int e = *id;
    return (e == 0) ? NULL : tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;
    else if (value < tree->data)
        return find(tree->left, value);
    else if (value > tree->data)
        return find(tree->right, value);
    else
    {
        return tree;
    }
}

void free_bst(struct bst_node *tree)
{
    if (tree)
    {
        if (!tree->left)
        {
            if (!tree->right)
            {
                free(tree);
                tree = NULL;
            }
            else
            {
                free_bst(tree->right);
                free(tree);
                tree = NULL;
            }
        }
        else
        {
            if (!tree->right)
            {
                free_bst(tree->left);
                free(tree);
                tree = NULL;
            }
            else
            {
                free_bst(tree->left);
                free_bst(tree->right);
                free(tree);
                tree = NULL;
            }
        }
    }
}
