#include "main.h"
/**
 * is_pos_int - check if the string is positive int
 * @s: the string to work on
 * Return: 1 if yes, 0 if no
 */
int is_pos_int(char *s)
{
	int index = 0;

	if (!s)
	{
		return (0);
	}
	while (s[index])
	{
		if (s[index] < '0' || s[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

/**
 * _atoi - convert a string into an integer
 * @s: string to convert
 * Return: On success: the int result, On failure: 0
 */
int _atoi(char *s)
{
	int i = 0, n = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return (n);
}

/**
 * _itoa - convert int to str
 * @n: int to convert
 * Return: the string
 */

char *_itoa(int n)
{
	static char str[12];
	int i = 0, rem, end;
	int isNegative = 0, start;
	char temp;

	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (n < 0)
	{
		isNegative = 1;
		n = -n;
	}

	while (n != 0)
	{
		rem = n % 10;
		str[i++] = rem + '0';
		n = n / 10;
	}

	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';

	for (start = 0, end = i - 1; start < end; start++, end--)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}

	return (str);
}

