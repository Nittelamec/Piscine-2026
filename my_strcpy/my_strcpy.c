#include <stddef.h>

char *my_strcpy(char *dest, const char *source)
{
    size_t len = 0;
    size_t i;
    while (source[len] != '\0')
        len++;
    for (i = 0; i < len && source[i] != '\0'; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}
