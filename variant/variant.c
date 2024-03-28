#include "variant.h"

#include <stddef.h>
#include <stdio.h>

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t i = 0;
    size_t len = (len1 > len2) ? len2 : len1;
    while (s1[i] == s2[i] && i < len)
    {
        i++;
    }
    return s1[i] - s2[i];
}

void variant_display(const struct variant *e)
{
    if (e == NULL)
    {
        return;
    }
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    default:
        return;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    else if (left->type != right->type)
    {
        return false;
    }
    else
    {
        switch (left->type)
        {
        case TYPE_INT:
            return (left->value.int_v == right->value.int_v);
            break;
        case TYPE_FLOAT:
            return (left->value.float_v == right->value.float_v);
            break;
        case TYPE_CHAR:
            return (left->value.char_v == right->value.char_v);
            break;
        case TYPE_STRING:
            return (my_strcmp(left->value.str_v, right->value.str_v) == 0);
            break;
        default:
            return false;
        }
    }
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    if (!array || len == 0)
        return -1;
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            if (array[i].type == type)
            {
                switch (type)
                {
                case TYPE_INT:
                    if (array[i].value.int_v == value.int_v)
                        return i;
                    break;
                case TYPE_FLOAT:
                    if (array[i].value.float_v == value.float_v)
                        return i;
                    break;
                case TYPE_CHAR:
                    if (array[i].value.char_v == value.char_v)
                        return i;
                    break;
                case TYPE_STRING:
                    if (array[i].value.str_v == value.str_v)
                        return i;
                    break;
                default:
                    return -1;
                }
            }
        }
        return -1;
    }
}

float variant_sum(const struct variant *array, size_t len)
{
    if (!array || len == 0)
        return 0;
    float sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        switch (array[i].type)
        {
        case TYPE_INT:
            sum += array[i].value.int_v;
            break;
        case TYPE_FLOAT:
            sum += array[i].value.float_v;
            break;
        default:
            sum += 0;
        }
    }
    return sum;
}
