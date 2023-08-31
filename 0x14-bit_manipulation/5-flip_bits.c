#inlcude "main.h"

/**
 * flip_bits - Count the number of bits needed to flip to get from n to m.
 * @n: First unsigned long integer.
 * @m: Second unsigned long integer.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0) {
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return count;
}
