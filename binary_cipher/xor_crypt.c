#include <stddef.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *cast_data = data;
    const char *cast_key = key;
    for (size_t i = 0; i < data_len; i++)
        cast_data[i] = cast_data[i] ^ cast_key[i % key_len];
}
