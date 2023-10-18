#include "main.h"
/**
 * my_getline - get the input
 * @line: input ended by newline
 * @n: the init size
 * Return: the number of chars entered
 */
ssize_t my_getline(char **line, size_t *n)
{
	ssize_t result, bytesRead = 0;
	size_t new_size, bufferSize = 128;
	char ch, *new_line;

	if (line == NULL || n == NULL)
	{
		return (-1);
	}
	*line = (char *)malloc(bufferSize);
	if (*line == NULL)
	{
		return (-1);
	}
	while (1)
	{
		result = read(STDIN_FILENO, &ch, 1);
		if (result == -1)
		{
			return (-1);
		}
		else
			if (result == 0)
			{
				break;
			}
		if (bytesRead + 1 >= bufferSize)
		{
			new_size = bufferSize * 2;
			*new_line = (char *)realloc(*line, new_size);
			if (new_line == NULL)
			{
				return (-1);
			}
			*line = new_line;
			bufferSize = new_size;
		}
		(*line)[bytesRead] = ch;
		bytesRead++;
		if (ch == '\n')
		{
			break;
		}
	}
	if (bytesRead == 0)
	{
		return (-1);
	}
	(*line)[bytesRead] = '\0';
	return (bytesRead);
}
