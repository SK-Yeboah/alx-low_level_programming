#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: num of prented
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int flag = 0;
	
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	
	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	
	while (mask)
	{
		if (n & mask)
			flag = 1;
		if (flag)
			if (n & mask)
				_putchar('1');
			else
				_putchar('0');

        mask >>= 1;
    }
}
