#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

static int my_fopen(FILE **fin, const char *path, const char *mode)
{
    *fin = fopen(path, mode);
    if (!(*fin))
        return -1;
    return 0;
}

static void close_files(FILE *f1, FILE *f2, char *ptr)
{
    if (f1)
        fclose(f1);
    if (f2)
        fclose(f2);
    if (ptr)
        free(ptr);
}

static int find_newline(const char *str)
{
    size_t i = 0;
    size_t res = 0;
    if (str)
    {
        while (str[i] != '\0')
        {
            if (str[i] == '\n')
                res++;
            i++;
        }
    }
    return res;
}

static size_t my_strlen(const char *str)
{
    size_t res = 0;
    if (str)
    {
        while (str[res] != '\0')
            res++;
    }
    return res;
}

static void insert_content(FILE *fin, FILE *fout, const char *content,
                           char *ptr)
{
    if (content && my_strlen(content))
    {
        if (fputs(content, fout) == EOF)
        {
            close_files(fin, fout, ptr);
            errx(-1, "insert_content: fputs failed");
        }
    }
}

static int padding(FILE *f, size_t *nblines, size_t n)
{
    for (; *nblines < n; (*nblines)++)
    {
        if (fputs("\n", f) == EOF)
            return -1;
    }
    return 0;
}

static int __insert_line(FILE *fin, FILE *fout, char *lineptr, size_t *nblines)
{
    ssize_t nread = 0;
    size_t size = 0;
    while (nread >= 0)
    {
        if (fputs(lineptr, fout) == EOF)
            return -1;
        (*nblines)++;
        nread = getline(&lineptr, &size, fin);
    }
    free(lineptr);
    return 0;
}

static void no_linefeed(const char *content, size_t *nblines)
{
    if (content[my_strlen(content) - 1] != '\n')
        (*nblines)++;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out || !content)
        return -1;

    FILE *fin;
    FILE *fout;
    if (my_fopen(&fin, file_in, "r") < 0 || my_fopen(&fout, file_out, "w") < 0)
        return -1;

    size_t nblines = 0;
    char *lineptr = NULL;
    size_t size = 0;
    ssize_t nread = getline(&lineptr, &size, fin);
    while (nblines < n && nread >= 0)
    {
        fputs(lineptr, fout);
        nblines++;
        nread = getline(&lineptr, &size, fin);
    }
    if (nblines == n)
    {
        insert_content(fin, fout, content, lineptr);
        if (nread < 0)
            no_linefeed(content, &nblines);
        else
        {
            if (__insert_line(fin, fout, lineptr, &nblines) < 0)
            {
                close_files(fin, fout, lineptr);
                return -1;
            }
        }
    }
    else
    {
        if (padding(fout, &nblines, n) < 0)
        {
            close_files(fin, fout, lineptr);
            return -1;
        }
        insert_content(fin, fout, content, lineptr);
        no_linefeed(content, &nblines);
    }

    close_files(fin, fout, lineptr);
    return nblines + find_newline(content);
}
