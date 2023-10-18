#include "main.h"
/**
 * _strdup - duplicate a string.
 *
 * @str: the string to duplicate.
 *
 * Return: duplicated string.
 */
char *_strdup(char *str)
{
	size_t length = 0;
	char *new_str = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	length = _strlen(str);
	new_str = (char *)malloc(length + 1); /* +1 for the null terminator */

	if (new_str == NULL)
	{
		return (NULL); /* Memory allocation failed */
	}

	_strcpy(new_str, str);

	return (new_str);
}

