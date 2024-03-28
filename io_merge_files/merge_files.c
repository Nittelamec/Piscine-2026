#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

#define BUFFERSIZE 1024

int merge_files(const char *file_1, const char *file_2)
{
    FILE *f1 = fopen(file_1, "a");
    FILE *f2 = fopen(file_2, "r");
    if (!f1 || !f2)
        return -1;

    char c;
    while ((c = fgetc(f2)) != EOF)
    {
        if (fputc(c, f1) == EOF)
            return -1;
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
