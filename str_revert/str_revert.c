#include <stddef.h>

void str_revert(char s[])
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    if (len == 1 || len == 0)
        return;
    size_t i = 0;
    size_t j = len - i - 1;
    while (i < j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    return;
}
