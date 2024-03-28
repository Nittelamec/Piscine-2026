#include "my_memcmp.h"

int my_strcmp(const char *s1, const char *s2, size_t len)
{
    if (len == 0)
        return 0;
    size_t i = 0;
    while (s1[i] == s2[i] && i < len)
    {
        i++;
    }
    return s1[i] - s2[i];
}

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    return my_strcmp(s1, s2, num);
}
