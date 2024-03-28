void init(unsigned char *lights)
{
    unsigned char not_lights = ~(*lights);
    *lights = *lights & not_lights;
}
void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);
    *lights = *lights | mask;
}
void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = ~(1 << (light_num - 1));
    *lights = *lights & mask;
}
void next_step(unsigned char *lights)
{
    unsigned char tmp = *lights;
    unsigned char mask = tmp >> 3;
    *lights = *lights << 1;
    *lights = *lights | mask;
    for (int i = 0; i < 4; i++)
        turn_off(lights, 8 - i);
}
void reverse(unsigned char *lights)
{
    *lights = ~(*lights);
    for (int i = 0; i < 4; i++)
        turn_off(lights, 8 - i);
}
void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    unsigned char tmp = *lights_1;
    *lights_1 = *lights_2;
    *lights_2 = tmp;
}
