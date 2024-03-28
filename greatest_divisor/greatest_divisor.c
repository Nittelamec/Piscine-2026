unsigned int greatest_divisor(unsigned int n)
{
    unsigned int g_div = 1;
    for (unsigned int i = 1; i < (n / 2) + 1; i++)
    {
        if (n % i == 0)
        {
            g_div = i;
        }
    }
    return g_div;
}
