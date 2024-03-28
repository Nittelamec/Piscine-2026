#include "my_strspn.h"

static int is_char_accepted(char c, const char *accept)
{
    int res = 0;
    for (size_t j = 0; accept[j] != '\0'; j++)
    {
        if (c == accept[j])
            res = 1;
    }
    return res;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t pos = 0;
    while (s[pos] != '\0' && is_char_accepted(s[pos], accept))
        pos++;
    return pos;
}
