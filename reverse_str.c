#include "main.h"

/**
 * reverse_str -  reverses a string
 *
 * @str: The string to reverse.
 *
 * Return: The reversed str.
 */

char *reverse_str(char *str)
{
	int left = 0;
	int right = _strlen(str) - 1;
	char temp;

	while (left < right)
	{
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}

	return (str);
}
