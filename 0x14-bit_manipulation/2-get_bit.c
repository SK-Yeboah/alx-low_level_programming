#include "main.h"
/**
 * get_bit - Returns the value of a bit at a specified index.
 * @n: The number whose bits are being checked.
 * @index: The index of the bit to be checked.
 *
 *
 * Return: The value of the bit at the specified index (0 or 1).
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int di, re;

	if (index > sizeof(unsigned long int) * 8 - 1)
		return -1;

	di = 1UL << index;
	re = n & di;

	if (re == di)
		return (1);

	return (0);
}
