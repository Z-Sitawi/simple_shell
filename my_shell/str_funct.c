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

/**
 * _strcpy - copy string from src to dest
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int my_getchar() {
    char c;
    ssize_t bytesRead = read(STDIN_FILENO, &c, 1);

    if (bytesRead == 0) {
        return EOF; // End of file
    } else if (bytesRead == -1) {
        return EOF; // Error reading
    } else {
        return (int)c;
    }
}
