#include <stdio.h>

static int my_fopen(FILE **f, const char *mode, const char *path)
{
    *f = fopen(path, mode);
    if (!(*f))
        return -1;
    return 0;
}

static void files_close(FILE *f1, FILE *f2)
{
    if (f1)
        fclose(f1);
    if (f2)
        fclose(f2);
}

int reverse_content(const char *file_in, const char *file_out)
{
    if (!file_in || !file_out)
        return -1;
    FILE *fin;
    FILE *fout;
    if (my_fopen(&fin, "r", file_in) < 0 || my_fopen(&fout, "w", file_out) < 0)
        return -1;

    int offset = 0;
    char c;
    while ((fseek(fin, --offset, SEEK_END) == 0))
    {
        c = fgetc(fin);
        fputc(c, fout);
    }

    files_close(fin, fout);
    return 0;
}
