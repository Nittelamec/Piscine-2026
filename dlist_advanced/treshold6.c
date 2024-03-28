#include "dlist.h"

static size_t my_strlen(const char *s, size_t begin)
{
    size_t cmp = 0;
    int i = begin;
    while (s[i] != '\0')
    {
        cmp++;
        i++;
    }
    return cmp;
}

static size_t smax(size_t a, size_t b)
{
    return (a > b) ? a : b;
}

static size_t smin(size_t a, size_t b, size_t c)
{
    if (a < b)
    {
        if (c < a)
            return c;
        return a;
    }
    else
    {
        if (c < b)
            return c;
        return b;
    }
}

static size_t rec(const char *s1, const char *s2, int i, int j)
{
    size_t lens1 = my_strlen(s1, i);
    size_t lens2 = my_strlen(s2, j);
    if (lens1 == 0 || lens2 == 0)
    {
        return smax(lens1, lens2);
    }
    else if (s1[i] == s2[j])
    {
        return rec(s1, s2, i + 1, j + 1);
    }
    else
    {
        return 1
            + smin(rec(s1, s2, i + 1, j), rec(s1, s2, i, j + 1),
                   rec(s1, s2, i + 1, j + 1));
    }
}

size_t levenshtein(const char *s1, const char *s2)
{
    return rec(s1, s2, 0, 0);
}

void str_fill(struct dlist *list, char *str)
{
    for (size_t i = 0; i < list->size; i++)
    {
        char c = dlist_get(list, i);
        str[i] = c;
    }
    str[list->size] = '\0';
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    if (list1 && list2)
    {
        char *str1 = malloc(list1->size + 1);
        char *str2 = malloc(list2->size + 1);
        str_fill(list1, str1);
        str_fill(list2, str2);
        unsigned int res = levenshtein(str1, str2);
        free(str1);
        free(str2);
        return res;
    }
    else
        return 0;
}
