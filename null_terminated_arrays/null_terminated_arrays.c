#include "null_terminated_arrays.h"

#include <stddef.h>

void swap_string(const char **s1, const char **s2)
{
    const char *tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void swap_string_array(const char ***s1, const char ***s2)
{
    const char **tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void reverse_matrix(const char ***matrix)
{
    size_t n = 0;
    while (matrix[n] != NULL)
    {
        size_t ni = 0;
        while (matrix[n][ni] != NULL)
            ni++;
        for (size_t j = 0; j < ni / 2; j++)
            swap_string(&(matrix[n][j]), &(matrix[n][ni - 1 - j]));
        n++;
    }
    for (size_t i = 0; i < n / 2; i++)
        swap_string_array(&matrix[i], &matrix[n - 1 - i]);
}
