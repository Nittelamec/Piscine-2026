#include <stdio.h>

void rec_hanoi(unsigned int n, int source, int spare, int target)
{
    if (n == 0)
        return;
    rec_hanoi(n - 1, source, target, spare);
    printf("%d->%d\n", source, target);
    rec_hanoi(n - 1, spare, source, target);
}

void hanoi(unsigned int n)
{
    rec_hanoi(n, 1, 2, 3);
    return;
}
