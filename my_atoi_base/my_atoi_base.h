#ifndef MY_ATOI_BASE_H
#define MY_ATOI_BASE_H

#include <stddef.h>
#include <stdio.h>

size_t strlen(const char *str);

size_t my_pow(int a, int b);

int aux(const char *str, size_t start, const char *base);

int is_in_base(const char *str, const char *base, size_t start);

int pos_in_base(char s, const char *base);

int my_atoi_base(const char *str, const char *base);

#endif // MY_ATOI_BASE_H
