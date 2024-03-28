#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    const char *s = source;
    char *d = dest;
    if (source > dest)
    {
        for (size_t i = 0; i < num; i++)
        {
            *(d + i) = *(s + i);
        }
        return dest;
    }
    else
    {
        for (size_t i = num; i > 0; i--)
        {
            *(d + (i - 1)) = *(s + (i - 1));
        }
        return dest;
    }
}
