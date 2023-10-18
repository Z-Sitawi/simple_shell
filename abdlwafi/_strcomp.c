#include "main.h"

/**
 * _strcomp - compares two strings
 *
 * @str1: first string to compare
 * @str2: second string to compare
 *
 * Return: 0 if the strings are equal
 * a negative value if str1 is lexicographically less than str2
 * a positive value if str1 is lexicographically greater than str2
 */

int _strcomp(char *str1, char *str2)
{
	int compare;

	while ((*str1 != '\0') && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	compare = (int)*str1 - (int)*str2;
	return (compare);
}
