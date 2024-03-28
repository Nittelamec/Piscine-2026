#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

static int my_fopen(FILE **f, const char *mode, const char *path)
{
    *f = fopen(path, mode);
    if (!(*f))
        return -1;
    return 0;
}

static void files_close(FILE *f1, FILE *f2, char *ptr)
{
    if (f1)
        fclose(f1);
    if (f2)
        fclose(f2);
    if (ptr)
        free(ptr);
}

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *fin;
    FILE *fout;

    if (my_fopen(&fin, "r", file_in) < 0 || my_fopen(&fout, "w", file_out) < 0)
        return -1;

    char *lineptr = NULL;
    size_t size = 0;
    ssize_t nread;
    nread = getline(&lineptr, &size, fin);

    int nlines = 0;

    while (nread >= 0)
    {
        if (nlines == n)
            fputs(content, fout);
        else
            fputs(lineptr, fout);
        nlines++;
        nread = getline(&lineptr, &size, fin);
    }
    files_close(fin, fout, lineptr);
    return (nlines < n) ? 1 : 0;
}
