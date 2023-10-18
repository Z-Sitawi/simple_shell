#include "main.h"

/**
 * main - main my shell function
 * @ac: args counter
 * @av: args array
 *
 * Return: always 0.
 */
int main(int ac, char **av)
{
	char *prompt = "Alx@My_Shell$ ";
	char *line = NULL, *line_copy = NULL, *token = NULL;
	int i, token_count;
	const char *delim = " \n";
	ssize_t size_read;
	size_t line_size;

	/* set ac and av as void for now */
	(void)ac;

	while (1)
	{
		line_size = 0;
		token_count = 0;
		/* todo: change printf by my own function */
		write(STDOUT_FILENO,prompt, 14);
		size_read = my_getline(&line, &line_size);
		if (size_read == -1)
		{
			/* todo: may removed after */
			write(STDIN_FILENO, "Exiting the shell...\n", 21);
			return (-1);
		}
		line_copy = malloc(size_read * sizeof(char));
		if (line_copy == NULL)
		{
			perror("hsh: memory allocation error.");
			return (-1);
		}
		_strcpy(line_copy, line);
		/* todo: strtok change */
		token = strtok(line, delim);
		while (token != NULL)
		{
			token_count++;
			printf("%s\n", token);
			token = strtok(NULL, delim);
		}
		printf("%d\n", token_count);
		av = malloc(token_count * sizeof(char *));
		if (av == NULL)
		{
			perror("hsh: av memory allocation error.");
			return (-1);
		}
		/* todo: strtok */
		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(av[i], token);
			/* todo: strtok */
			printf("av[%d]: %s\n", i, av[i]);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		/* todo: change printf */
		for (i = 0; i < token_count; i++)
		{
			printf("after: %s\n", av[i]);
		}
		free(av);
		free(line_copy);
	}
	free(line);
	return (0);
}
