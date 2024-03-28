#include "binary_tree.h"

#include <stddef.h>
#include <stdio.h>

static int my_pow(int x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    else
    {
        if (n % 2 == 0)
        {
            return my_pow(x * x, n / 2);
        }
        else
        {
            return x * my_pow(x * x, (n - 1) / 2);
        }
    }
}

int size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + size(tree->left) + size(tree->right);
}

static int tmax(int a, int b)
{
    return (a > b) ? a : b;
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    else
        return 1 + tmax(height(tree->left), height(tree->right));
}

int is_perfect(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return ((size(tree) + 1) == my_pow(2, height(tree) + 1));
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", tree->data);
        dfs_print_prefix(tree->left);
        dfs_print_prefix(tree->right);
        return;
    }
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        dfs_print_infix(tree->left);
        printf("%d ", tree->data);
        dfs_print_infix(tree->right);
        return;
    }
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        dfs_print_postfix(tree->left);
        dfs_print_postfix(tree->right);
        printf("%d ", tree->data);
        return;
    }
}

static int rec_complete(const struct binary_tree *tree, int i, int nodes)
{
    if (tree == NULL)
        return 1;
    else if (i >= nodes)
        return 0;
    else
        return (rec_complete(tree->left, 2 * i + 1, nodes)
                && rec_complete(tree->right, 2 * i + 2, nodes));
}

int is_complete(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int nodes = size(tree);
    return rec_complete(tree, 0, nodes);
}

static int rec_degenerate(const struct binary_tree *tree)
{
    if (tree->left == NULL)
    {
        if (tree->right == NULL)
            return 1;
        return rec_degenerate(tree->right);
    }
    else
    {
        if (tree->right == NULL)
            return rec_degenerate(tree->left);
        return 0;
    }
}

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    return rec_degenerate(tree);
}

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    else if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        return (is_full(tree->left) && is_full(tree->right));
    }
    return 0;
}

static int rec_bst(const struct binary_tree *tree, int min, int max)
{
    if (tree->data < min || tree->data > max)
        return 0;
    else if (tree->left == NULL)
    {
        if (tree->right == NULL)
        {
            return 1;
        }
        else
            return rec_bst(tree->right, tree->data, max);
    }
    else
    {
        if (tree->right == NULL)
            return rec_bst(tree->left, min, tree->data);
        else
        {
            return (rec_bst(tree->left, min, tree->data)
                    && rec_bst(tree->right, tree->data, max));
        }
    }
}

int is_bst(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    else
        return rec_bst(tree, -2147483648, 2147483647);
}
