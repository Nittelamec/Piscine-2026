#include <stddef.h>

int is_alpha_num(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    if (len == 0 || len == 1)
        return 1;
    size_t i = 0;
    size_t j = len - i - 1;
    while ((i < j))
    {
        if (is_alpha_num(s[i]) == 1)
        {
            if (is_alpha_num(s[j]) == 1)
            {
                if (s[i] != s[j])
                {
                    return 0;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    return 1;
}
