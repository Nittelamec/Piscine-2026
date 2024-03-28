#include "hill_array.h"

#include <assert.h>
#include <stdio.h>

/*return the lastest max even if there are equals values*/
size_t max_hill(int tab[], size_t len)
{
    size_t pos_max = 0;
    int max = tab[0];
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] > max)
        {
            pos_max = i;
            max = tab[i];
        }
    }
    return pos_max;
}

int is_incr_hill(int tab[], size_t top)
{
    for (size_t i = 0; i < top; i++)
    {
        if (tab[i] > tab[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int is_decr_hill(int tab[], size_t top, size_t len)
{
    for (size_t i = top; i < len - 1; i++)
    {
        if (tab[i] < tab[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int is_pos_hill(int tab[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] < 0)
            return 0;
    }
    return 1;
}

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0 || is_pos_hill(tab, len) == 0)
        return -1;
    size_t pos_top = max_hill(tab, len);
    if (is_incr_hill(tab, pos_top) == 1 && is_decr_hill(tab, pos_top, len) == 1)
        return pos_top;
    else
        return -1;
}
