#include "main.h"

/**
 * set_bit - Set a specific bit in an unsigned long integer.
 * @n: Pointer to the unsigned long integer whose bit to set.
 * @index: Index of the bit to be set.
 *
 *
 * Return: 1 on success, -1 if the index is out of range.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = 1 << index;
	*n = *n | i;

	return (1);
}
