#include "hash_map.h"

static struct pair_list *pair_list_init(const char *key, char *value)
{
    struct pair_list *new = malloc(sizeof(struct pair_list));
    if (!new)
        return NULL;
    new->key = key;
    new->value = value;
    new->next = NULL;
    return new;
}

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *new = malloc(sizeof(struct hash_map));
    struct pair_list **data = malloc(size * sizeof(struct pair_list *));
    if (!data || !new)
        return NULL;
    size_t i = 0;
    while (i < size)
    {
        data[i] = NULL;
        i++;
    }
    new->data = data;
    new->size = size;
    return new;
}

static size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

static int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t i = 0;
    size_t len = (len1 > len2) ? len2 : len1;
    while (s1[i] == s2[i] && i < len)
    {
        i++;
    }
    return s1[i] - s2[i];
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map && hash_map->size > 0)
    {
        size_t hash_value = hash(key);
        if (hash_value >= hash_map->size)
            hash_value %= hash_map->size;
        struct pair_list *actual = hash_map->data[hash_value];
        while (actual && my_strcmp(actual->key, key) != 0)
            actual = actual->next;
        if (!actual) // there is no such key, lets prepend it
        {
            struct pair_list *tmp = hash_map->data[hash_value];
            struct pair_list *new = pair_list_init(key, value);
            if (!new)
                return false;
            hash_map->data[hash_value] = new;
            new->next = tmp;
            if (updated)
                *updated = false;
            return true;
        }
        else // this key already exists, lets update its value
        {
            actual->value = value;
            if (updated)
                *updated = true;
            return true;
        }
    }
    else
        return false;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map)
    {
        size_t hsize = hash_map->size;
        for (size_t i = 0; i < hsize; i++)
        {
            if (hash_map->data[i] != NULL)
            {
                while (hash_map->data[i] != NULL)
                {
                    struct pair_list *next = hash_map->data[i]->next;
                    free(hash_map->data[i]);
                    hash_map->data[i] = next;
                }
            }
        }
        free(hash_map->data);
        free(hash_map);
    }
}

void hash_map_dump(struct hash_map *hash_map)
{
    size_t hsize = hash_map->size;
    for (size_t i = 0; i < hsize; i++)
    {
        if (hash_map->data[i])
        {
            struct pair_list *actual = hash_map->data[i];
            while (actual)
            {
                if (!actual->next)
                {
                    printf("%s: %s\n", actual->key, actual->value);
                    actual = actual->next;
                }
                else
                {
                    printf("%s: %s, ", actual->key, actual->value);
                    actual = actual->next;
                }
            }
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map && hash_map->size > 0)
    {
        size_t hash_value = hash(key);
        if (hash_value >= hash_map->size)
            hash_value %= hash_map->size;
        struct pair_list *actual = hash_map->data[hash_value];
        while (actual && my_strcmp(actual->key, key) != 0)
            actual = actual->next;
        if (!actual)
            return NULL;
        else
            return actual->value;
    }
    else
        return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map && hash_map->size > 0)
    {
        size_t hash_value = hash(key);
        if (hash_value >= hash_map->size)
            hash_value %= hash_map->size;
        struct pair_list *actual = hash_map->data[hash_value];
        if (actual && my_strcmp(actual->key, key) == 0) // first element
        {
            struct pair_list *hook = actual->next;
            free(actual);
            hash_map->data[hash_value] = hook;
            return true;
        }
        else
        {
            struct pair_list *prec;
            while (actual && my_strcmp(actual->key, key) != 0)
            {
                prec = actual;
                actual = actual->next;
            }
            if (!actual)
                return false;
            prec->next = actual->next;
            free(actual);
            return true;
        }
    }
    else
        return false;
}
