#include "main.h"

void print_binary(unsigned long int n)
{
    unsigned long int mask;

    int flag = 0;
    if (n == 0) {
        putchar('0');
        return;
    }

    mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

    while (mask) {
        if (n & mask)
            flag = 1;

        if (flag)
            putchar((n & mask) ? '1' : '0');

        mask >>= 1;
    }
}
