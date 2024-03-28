#include "my_itoa_base.h"

int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    if (n == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }
    int len_base = my_strlen(base);
    size_t cpt = 0;
    if (n < 0 && len_base == 10)
    {
        s[0] = '-';
        cpt++;
        n = -n;
    }
    while (n != 0)
    {
        int c = n % len_base;
        s[cpt] = base[c];
        cpt++;
        n = n / len_base;
    }
    s[cpt] = '\0';
    size_t i = 0;
    size_t j = cpt - i - 1;
    while (i < j)
    {
        if (s[i] == '-')
            i++;
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }

    return s;
}
