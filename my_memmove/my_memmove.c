#include "my_memmove.h"

void *my_memmove(void *dest, const void *source, size_t n)
{
    const char *s = source;
    char *d = dest;
    if (source > dest)
    {
        for (size_t i = 0; i < n; i++)
        {
            *(d + i) = *(s + i);
        }
        return dest;
    }
    else
    {
        for (size_t i = n; i > 0; i--)
        {
            *(d + (i - 1)) = *(s + (i - 1));
        }
        return dest;
    }
}
