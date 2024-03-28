#ifndef MY_ITOA_BASE_H
#define MY_ITOA_BASE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *str);

char *my_itoa_base(int n, char *s, const char *base);

#endif // MY_ITOA_BASE_H
