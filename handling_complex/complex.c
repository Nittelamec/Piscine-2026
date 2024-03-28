#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    float r = a.real;
    float im = a.img;
    if (im < 0)
    {
        printf("complex(%.2f - %.2fi)\n", r, -im);
    }
    else
        printf("complex(%.2f + %.2fi)\n", r, im);
}

struct complex neg_complex(struct complex a)
{
    struct complex z = a;
    z.real = -a.real;
    z.img = -a.img;
    return z;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex sum;
    sum.real = a.real + b.real;
    sum.img = a.img + b.img;
    return sum;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex sub;
    sub.real = a.real - b.real;
    sub.img = a.img - b.img;
    return sub;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex mult;
    mult.real = (a.real * b.real - a.img * b.img);
    mult.img = (a.real * b.img + a.img * b.real);
    return mult;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex div;
    div.real =
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
    div.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
    return div;
}
