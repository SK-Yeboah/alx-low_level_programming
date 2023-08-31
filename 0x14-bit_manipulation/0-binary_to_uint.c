#index "main.h"

/**
 * binary_to_uint - a function that converts a binary number
 *                  to an unsigned int
 *
 * @b: string that contains 0 and 1 characters
 *
 * Return: the number converted or 0
 *         if @b contains a character
 *         that is not 0 or 1 or when
 *         @b is null
*/

unsigned int binary_to_unit(const *b)
{
	unsigned int bit;
	unsigned int result = 0;
	int index = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[index] != '0' && b[index] != '1')
	{
		if (b[index] != '0' && b[index] != '1')
		{
			return (0);
		}

		bit  = b[index] - '0';

		result = (result << 1) | bit;
		index++;
	}

return (result);

}
