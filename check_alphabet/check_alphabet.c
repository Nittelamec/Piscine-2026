#include "check_alphabet.h"

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
        return 1;
    size_t len_alph = strlen(alphabet);
    if (len_alph == 0)
        return 1;
    size_t len_str = strlen(str);
    int cmp;
    for (size_t i = 0; i < len_alph; i++)
    {
        cmp = 0;
        for (size_t j = 0; j < len_str; j++)
        {
            if (str[j] == alphabet[i])
                cmp++;
        }
        if (cmp == 0)
            return 0;
    }
    return 1;
}
