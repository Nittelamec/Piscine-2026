#include <stdio.h>

int main(int argc, char **argv)
{
    int status = 0;
    if (argc != 3)
    {
        status = 1;
    }
    else
    {
        int n = argv[argc - 1][0] - '0';
        for (int i = 0; i < n; i++)
        {
            puts(argv[1]);
        }
    }
    return status;
}
