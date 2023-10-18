#include "main.h"
/**
 * _strlen - count the length of str
 * @str: string to work on
 * Return: the length of the string as int
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
