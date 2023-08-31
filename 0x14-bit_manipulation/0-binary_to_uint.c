#index "main.h"

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
