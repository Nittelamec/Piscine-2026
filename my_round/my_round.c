int my_round(float n)
{
    int res = n;
    if (res == 0)
    {
        res = 0;
    }
    else if (res < 0)
    {
        if ((-n) + res < 0.5)
        {
            return res;
        }
        else
        {
            return res - 1;
        }
    }
    else
    {
        if (n - res < 0.5)
        {
            return res;
        }
        else
        {
            return res + 1;
        }
    }
    return res;
}
