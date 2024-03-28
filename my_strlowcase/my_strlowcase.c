#include "my_strlowcase.h"

void my_strlowcase(char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
        i++;
    }
    return;
}
