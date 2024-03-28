unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
    {
        return 0;
    }
    else
    {
        unsigned int res = n;
        for (int i = 0; i < k; i++)
        {
            res = n % 10;
            n = n / 10;
        }
        return res;
    }
}
