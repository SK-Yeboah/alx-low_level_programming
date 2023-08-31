#include "main.h"

/**
 * binary_to_unit - converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int j = 0;

	if (!b)
		return 0;

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return 0;
		i++;
	}

	i = 0;
	while (b[i] != '\0')
	{
		j <<= 1;
		if (b[i] == '1')
			j += 1;
		i++;
	}

	return j;
}
