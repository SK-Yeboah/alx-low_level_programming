#include "main.h"

/**
 * clear_bit - Clear a specific bit in an unsigned long integer.
 * @n: Pointer to the unsigned long integer whose bit to clear.
 * @index: Index of the bit to be cleared.
 *
 *
 * Return: 1 on success, -1 if an error occurred (e.g., invalid index).
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index;
	*n = *n & ~mask;

	return (1);
}
