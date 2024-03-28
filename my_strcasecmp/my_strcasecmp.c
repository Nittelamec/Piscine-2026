#include <stddef.h>

int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

void to_lowcase(const char *source, char *dest)
{
    size_t len = my_strlen(source);
    for (size_t i = 0; i < len; i++)
    {
        if (is_alphanum(source[i]) == 1)
        {
            if (source[i] >= 'A' && source[i] <= 'Z')
                dest[i] = source[i] + 'a' - 'A';
            else
                dest[i] = source[i];
        }
        else
            dest[i] = source[i];
    }
    dest[len] = '\0';
}

int my_strcasecmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t i = 0;
    char dest1[200] = { '\0' };
    char dest2[200] = { '\0' };
    to_lowcase(s1, dest1);
    to_lowcase(s2, dest2);
    size_t len = (len1 > len2) ? len2 : len1;
    while (i < len)
    {
        if (dest1[i] == dest2[i])
            i++;
        else
            return dest1[i] - dest2[i];
    }
    return dest1[i] - dest2[i];
}
