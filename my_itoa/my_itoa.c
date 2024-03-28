#include "my_itoa.h"

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    size_t cpt = 0;
    if (value < 0)
    {
        value = -value;
        cpt++;
        s[0] = '-';
    }
    while (value != 0)
    {
        int c = value % 10;
        s[cpt] = '0' + c;
        cpt++;
        value = value / 10;
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
