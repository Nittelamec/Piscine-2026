#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFERSIZE 1024

static size_t my_strlen(const char *ptr)
{
    size_t res = 0;
    while (ptr[res] != '\0')
        res++;
    return res;
}

void stdintail(unsigned int n)
{
    char buffer;
    ssize_t nread;
    char mat[BUFFERSIZE][BUFFERSIZE];

    size_t nblines = 0;
    size_t i = 0;
    size_t j = 0;
    while ((nread = read(STDIN_FILENO, &buffer, 1)) > 0 && i < BUFFERSIZE
           && j < BUFFERSIZE)
    {
        if (buffer == '\n')
        {
            mat[i][j] = buffer;
            mat[i][j + 1] = '\0';
            nblines++;
            i++;
            j = 0;
        }
        else
        {
            mat[i][j] = buffer;
            j++;
        }
    }

    if (nblines < n)
        n = nblines;

    for (unsigned int k = 0; k < n; k++)
    {
        if (write(STDOUT_FILENO, mat[nblines - n + k],
                  my_strlen(mat[nblines - n + k]))
            < 0)
            return;
    }
}
