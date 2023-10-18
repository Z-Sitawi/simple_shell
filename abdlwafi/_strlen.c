#include "main.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: a string
 *
 * Return: len
 */
size_t _strlen(char *s)
{
	size_t length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
