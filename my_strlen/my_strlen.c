#include "my_strlen.h"

size_t my_strlen(const char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    else
    {
        size_t cmp = 0;
        int i = 0;
        while (s[i] != '\0')
        {
            cmp++;
            i++;
        }
        return cmp;
    }
}
