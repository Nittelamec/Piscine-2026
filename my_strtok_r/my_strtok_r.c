#include "my_strtok_r.h"

#include <stddef.h>

static int is_delim(char c, const char *delim)
{
    size_t i = 0;
    while (delim[i] != '\0')
    {
        if (delim[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;
    if (!str)
        str = *saveptr;
    while (is_delim(*str, delim))
        str += 1;
    if (*str == '\0')
        return NULL;
    else
    {
        char *res = str;
        while (*str != '\0')
        {
            end = str + 1;
            if (is_delim(*str, delim))
            {
                *str = '\0';
                str += 1;
                *saveptr = str;
                return res;
            }
            else
                str = str + 1;
        }
        if (*end == '\0')
        {
            *saveptr = str;
            return res;
        }
        return NULL;
    }
}
