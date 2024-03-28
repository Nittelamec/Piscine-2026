#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        return 1;
    }
    int fd = open(argv[argc - 1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return 1;
    }

    char c;
    ssize_t nread;
    int offst = -1;
    lseek(fd, offst--, SEEK_END);

    char res[3] = { 0, 0, '\n' };

    for (int i = 0; i < 2; i++)
    {
        while ((nread = read(fd, &c, 1)) > 0 && isspace(c))
            lseek(fd, offst--, SEEK_END);
        if (nread <= 0)
        {
            if (nread < 0)
                write(STDERR_FILENO, "spoilers: read file error\n", 26);
            else
                write(STDERR_FILENO, "File is not long enough\n", 24);
            return 1;
        }
        res[2 - i - 1] = c;
        lseek(fd, offst--, SEEK_END);
    }
    close(fd);
    write(STDOUT_FILENO, res, 3);
    return 0;
}
