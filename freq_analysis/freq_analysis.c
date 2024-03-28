#include <stdio.h>

int my_strlen(const char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    else
    {
        int cmp = 0;
        int i = 0;
        while (s[i] != '\0')
        {
            cmp++;
            i++;
        }
        return cmp;
    }
}

int max_hist(int t[])
{
    int max = t[0];
    int pos_max = 0;
    int i = 0;
    while (i < 26)
    {
        if (t[i] > max)
        {
            max = t[i];
            pos_max = i;
        }
        i++;
    }
    return pos_max;
}

void freq_analysis(const char text[], const char table[])
{
    int hist[26];
    for (int i = 0; i < 26; i++)
        hist[i] = -1;
    int len_txt = my_strlen(text);
    int len_table = my_strlen(table);
    for (int i = 0; text[i] != '\0'; i++)
    {
        int act = text[i];
        if (hist[act - 'A'] == -1)
        {
            hist[act - 'A'] += 2;
            for (int j = i + 1; j < len_txt; j++)
            {
                if (text[j] == act)
                    hist[act - 'A'] += 1;
            }
        }
    }
    char tab_print[26];
    for (int j = 0; j < 26; j++)
        tab_print[j] = '\0';
    for (int i = 0; i < len_table; i++)
    {
        int max = max_hist(hist);
        hist[max] = -2;
        tab_print[max] = table[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (tab_print[i] != '\0')
        {
            printf("%c %c\n", i + 'A', tab_print[i]);
        }
    }
}
