#include "simple_fnmatch.h"

#include <stddef.h>

int rec(const char *p, const char *s, size_t pos_string, size_t pos_pattern)
{
    if (p[pos_pattern] == '\0' && s[pos_string] == '\0')
        return 0;
    else
    {
        if (p[pos_pattern] == '?')
        {
            if (s[pos_string] == '\0')
                return FNM_NOMATCH;
            else
                return rec(p, s, pos_string + 1, pos_pattern + 1);
        }
        else if (p[pos_pattern] == '*')
        {
            if (p[pos_pattern + 1] == '\0')
                return 0;
            else
            {
                size_t i = 0;
                while (s[pos_string + i] != '\0')
                {
                    int tmp = rec(p, s, pos_string + i, pos_pattern + 1);
                    if (tmp == 0)
                        return 0;
                    else
                        i++;
                }
                return FNM_NOMATCH;
            }
        }
        else if (p[pos_pattern] == '\\')
        {
            if (p[pos_pattern + 1] == '\0'
                || s[pos_string] != p[pos_pattern + 1])
                return FNM_NOMATCH;
            else
                return rec(p, s, pos_string + 1, pos_pattern + 2);
        }
        else
            return (s[pos_string] != p[pos_pattern])
                ? FNM_NOMATCH
                : rec(p, s, pos_string + 1, pos_pattern + 1);
    }
}

int simple_fnmatch(const char *pattern, const char *string)
{
    return rec(pattern, string, 0, 0);
}
