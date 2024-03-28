unsigned long facto(unsigned n, unsigned accu)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return accu;
    }
    else
    {
        return facto(n - 1, n * accu);
    }
}

unsigned long fact(unsigned n)
{
    return facto(n, 1);
}
