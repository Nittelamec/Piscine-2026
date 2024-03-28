int aux(int a, int accu)
{
    if (a < 10)
    {
        return 10 * accu + a;
    }
    else
    {
        return aux(a / 10, accu * 10 + a % 10);
    }
}

int miroir(int n)
{
    return aux(n, 0);
}

int int_palindrome(int n)
{
    if (n >= 0)
    {
        if (n < 10)
        {
            return 1;
        }
        else
        {
            if (miroir(n) == n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
