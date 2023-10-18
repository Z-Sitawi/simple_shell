#include "main.h"
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	char *line = NULL;
	char **commands = NULL;
	int status = 0;

	(void)ac;

	while (1)
	{
		line = readline();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}

		commands = tokenize(line);
		if (!commands)
			continue;

		status = execute_cmd(commands, av);
	}
}
