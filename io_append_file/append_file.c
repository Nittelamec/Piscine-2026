#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    if (!content || !file_in)
        return -1;
    FILE *f = fopen(file_in, "a");
    if (!f)
        return -1;
    if (fseek(f, 0, SEEK_END) < 0)
    {
        fclose(f);
        return -1;
    }
    if (fprintf(f, "%s", content) < 0)
    {
        fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}
