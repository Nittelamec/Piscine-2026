unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char tmp = value;
    tmp = tmp >> (8 - roll) % 8;
    value = value << roll % 8;
    value = value | tmp;
    return value;
}
