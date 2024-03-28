#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void rot_x(char *s, int x)
{
    if (s == NULL)
        return;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] <= 'z' && s[i] >= 'a')
        {
            int c = s[i];
            c -= 'a';
            c = c + x;
            while (c < 0)
                c += 26;
            c = c % 26;
            s[i] = c + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int c = s[i];
            c -= 'A';
            c = c + x;
            while (c < 0)
                c += 26;
            c = c % 26;
            s[i] = c + 'A';
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            int c = s[i];
            c -= '0';
            c = c + x;
            while (c < 0)
                c += 10;
            c = c % 10;
            s[i] = c + '0';
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    char buffer[5000];
    ssize_t nread;
    ssize_t nwrite;
    int x = atoi(argv[argc - 1]);
    nread = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (nread == -1)
        return -1;
    rot_x(buffer, x);
    nwrite = write(STDOUT_FILENO, buffer, nread);
    if (nwrite == -1)
        return -1;
    return 0;
}
