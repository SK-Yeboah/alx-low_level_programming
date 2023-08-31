#inlcude "main.h"

/**
 * flip_bits - Count the number of bits needed to change
 * to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: The number of bits to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
	unsigned int count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 31; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
