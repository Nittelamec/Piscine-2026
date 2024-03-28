#include <stddef.h>

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

size_t smax(size_t a, size_t b)
{
    return (a > b) ? a : b;
}

size_t smin(size_t a, size_t b, size_t c)
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

size_t rec(const char *s1, const char *s2, int i, int j)
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
