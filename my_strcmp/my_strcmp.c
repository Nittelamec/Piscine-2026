#include <stddef.h>

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t i = 0;
    size_t len = (len1 > len2) ? len2 : len1;
    while (s1[i] == s2[i] && i < len)
    {
        i++;
    }
    return s1[i] - s2[i];
}
