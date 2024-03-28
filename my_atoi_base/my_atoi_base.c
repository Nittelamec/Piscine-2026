#include "my_atoi_base.h"

size_t strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

size_t my_pow(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
        return my_pow(a * a, b / 2);
    else
        return a * my_pow(a * a, (b - 1) / 2);
}

int aux(const char *str, size_t start, const char *base)
{
    int res = 0;
    size_t len = strlen(str);
    size_t lenbase = strlen(base);
    for (size_t i = start; i < len; i++)
    {
        res += pos_in_base(str[i], base) * my_pow(lenbase, len - i - 1);
    }
    return res;
}

int is_in_base(const char *str, const char *base, size_t start)
{
    size_t len = strlen(str);
    if (start >= len)
        return 0;
    if (str[start] == '+' || str[start] == '-')
        start++;
    size_t lenbase = strlen(base);
    int is_in = 1;
    for (size_t i = start; i < len; i++)
    {
        is_in = 0;
        for (size_t j = 0; j < lenbase; j++)
        {
            if (str[i] == base[j])
            {
                is_in++;
            }
        }
        if (!is_in)
            return 0;
    }
    return 1;
}

int pos_in_base(char s, const char *base)
{
    size_t i = 0; /*i is valid according to is_in_base*/
    while (s != base[i])
        i++;
    return i;
}

int my_atoi_base(const char *str, const char *base)
{
    size_t len = strlen(str);
    if (!len)
        return 0;
    int res = 0;
    size_t i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    char sign = str[i];
    int in_base = is_in_base(str, base, i);
    if (!in_base)
        return 0;
    if (sign == '+')
        res = aux(str, i + 1, base);
    else if (sign == '-')
        res = -aux(str, i + 1, base);
    else
        res = aux(str, i, base);
    return res;
}
