#include <stdio.h>

static int my_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return 1;
    return 0;
}

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;
    FILE *fin = fopen(file_in, "r");
    if (!fin)
        return -1;
    char c = fgetc(fin);
    int nbwords = 0;
    while (c != EOF)
    {
        if (!my_isspace(c))
        {
            nbwords++;
            while (c != EOF && !my_isspace(c))
                c = fgetc(fin);
        }
        c = fgetc(fin);
    }
    return nbwords;
}
