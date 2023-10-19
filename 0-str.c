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

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
	{
		a++;
	}
	for ( ; b < a ; b++)
	{
		dest[b] = src[b];
	}
	dest[a] = '\0';
	return (dest);
}

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

/**
 * _str_concat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_str_concat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}

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
	char *str3, *str4;

	str3 = str1;
	str4 = str2;
	while ((*str3 != '\0') && (*str3 == *str4))
	{
		str3++;
		str4++;
	}

	compare = (int)*str3 - (int)*str4;
	return (compare);
}
