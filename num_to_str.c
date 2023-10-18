#include "main.h"

/**
 * num_to_str -  converts an integer to a string.
 *
 * @n: The number to convert.
 *
 * Return: The string.
 */

char *num_to_str(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
	{
		buff[i++] = '0';
	}
	else
	{
		if (n < 0)
		{
			buff[i++] = '-';
			n = -n;
		}

		while (n > 0)
		{
			buff[i++] = '0' + (n % 10);
			n /= 10;
		}
	}

	buff[i] = '\0';

	reverse_str(buff);

	return (strdup(buff));
}
