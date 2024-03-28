static int my_strlen(const char *s)
{
    int cmp = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        cmp++;
        i++;
    }
    return cmp;
}

static char str[2000];
static char str2[2000];

static char *to_upper_key(const char *msg)
{
    int i = 0;
    while (msg[i] != '\0')
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (msg[j] >= 'A' && msg[j] <= 'Z')
            str2[j] = msg[j];
        else if (msg[j] >= 'a' && msg[j] <= 'z')
        {
            char c = msg[j];
            c = c + ('A' - 'a');
            str2[j] = c;
        }
        else
            str2[j] = msg[j];
    }
    str2[i] = '\0';
    return str2;
}

static char *to_upper(const char *msg)
{
    int k = 0;
    while (msg[k] != '\0')
    {
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            str[i] = msg[i];
        else if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            char c = msg[i];
            c = c + ('A' - 'a');
            str[i] = c;
        }
        else
            str[i] = msg[i];
    }
    str[k] = '\0';
    return str;
}

void cipher(const char *key, const char *msg, char *res)
{
    int i = 0;
    int key_pos = 0;
    int len_key = my_strlen(key);
    char *msg_up = to_upper(msg);
    char *key_up = to_upper_key(key);
    while (msg_up[i] != '\0')
    {
        if (msg_up[i] < 'A' || msg_up[i] > 'Z')
        {
            res[i] = msg_up[i];
            i++;
        }
        else
        {
            char c = msg_up[i];
            c = c - 'A';
            if (key_up[key_pos % len_key] > 'Z'
                || key_up[key_pos % len_key] < 'A')
                key_pos++;
            else
            {
                c = c + key_up[key_pos % len_key] - 'A';
                c = c % 26;
                res[i] = c + 'A';
                i++;
                key_pos++;
            }
        }
    }
    res[i] = '\0';
    return;
}

void decipher(const char *key, const char *msg, char *res)
{
    int i = 0;
    int key_pos = 0;
    int len_key = my_strlen(key);
    char *msg_up = to_upper(msg);
    char *key_up = to_upper_key(key);
    while (msg_up[i] != '\0')
    {
        if (msg_up[i] < 'A' || msg_up[i] > 'Z')
        {
            res[i] = msg_up[i];
            i++;
        }
        else
        {
            char c = msg_up[i];
            c = c - 'A';
            if (key_up[key_pos % len_key] > 'Z'
                || key_up[key_pos % len_key] < 'A')
                key_pos++;
            else
            {
                c = c - (key_up[key_pos % len_key] - 'A');
                if (c < 0)
                    c = c + 26;
                c = c % 26;
                res[i] = c + 'A';
                i++;
                key_pos++;
            }
        }
    }
    res[i] = '\0';
    return;
}
