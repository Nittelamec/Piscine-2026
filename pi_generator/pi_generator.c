double rec_pi(int precision, double i)
{
    if (precision == 0)
        return 1;
    return 1 + i / (2 * i + 1) * rec_pi(precision - 1, i + 1);
}

double pi_generator(int precision)
{
    return 2 * rec_pi(precision, 1);
}
