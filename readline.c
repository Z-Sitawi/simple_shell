#include "main.h"
/**
 * readline - reads the command line
 *
 * Return: line read.
 */

char *readline(void)
{
	char *line = NULL;
	size_t line_len = 0;
	ssize_t nbr;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	nbr = getline(&line, &line_len, stdin);

	if (nbr == -1)
	{
		free(line);
		line = NULL;
		return (NULL);
	}

	return (line);
}
