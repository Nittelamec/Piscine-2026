void rec(char **map, int i, int j)
{
    if (map[i + 1][j] == '.')
    {
        map[i + 1][j] = '#';
        rec(map, i + 1, j);
    }
    if (map[i][j + 1] == '.')
    {
        map[i][j + 1] = '#';
        rec(map, i, j + 1);
    }
    if (map[i - 1][j] == '.')
    {
        map[i - 1][j] = '#';
        rec(map, i - 1, j);
    }
    if (map[i][j - 1] == '.')
    {
        map[i][j - 1] = '#';
        rec(map, i, j - 1);
    }
    return;
}

int lakes(char **map, int width, int height)
{
    int res = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                res++;
                rec(map, i, j);
            }
        }
    }
    return res;
}
