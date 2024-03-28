#include "my_atoi.h"

int aux(const char *str, size_t start, char sign)
{
    int tmp = 0;
    size_t len = 0;
    while (str[len] != '\0')
        len++;
    for (size_t i = start; i < len; i++)
    {
        tmp *= 10;
        if (str[i] > '9' || str[i] < '0')
            return 0;
        tmp += str[i] - '0';
    }
    if (sign == '+')
        return tmp;
    else
    {
        return -tmp;
    }
}

int my_atoi(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
        len++;
    if (len == 0)
        return 0;
    int res = 0;
    size_t i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    if (i >= len)
        return 0;
    char sign = str[i];
    if (sign == '+' || sign == '-')
        res = aux(str, i + 1, sign);
    else if (sign <= '9' && sign >= '0')
        res = aux(str, i, '+');
    else
        res = 0;
    return res;
}
