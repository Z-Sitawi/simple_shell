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

/**
 * execute_cmd - executes commands in a child pid.
 * @cmd: command to execute.
 * @av: argument vector.
 *
 * Return: exit-s the value of status.
 */

int execute_cmd(char **cmd, char **av)
{
	pid_t child_PID_value;
	int status;

	child_PID_value = fork();

	if (child_PID_value == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(av[0]);
			free_array_of_str(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(child_PID_value, &status, 0);
		free_array_of_str(cmd);

	}

	return (WEXITSTATUS(status));
}

/**
 * execute_cmd - executes commands in a child pid.
 * @cmd: command to execute.
 * @av: argument vector.
 *
 * Return: exit-s the value of status.
 */

int execute_cmd(char **cmd, char **av)
{
	pid_t child_PID_value;
	int status;
	char *full_cmd;

	full_cmd = get_path(cmd[0]);
	if (!full_cmd)
	{
		show_error();
		free_array_of_str(cmd);
		return (127);
	}

	child_PID_value = fork();

	if (child_PID_value == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			free_array_of_str(cmd);
		}
	}
	else
	{
		waitpid(child_PID_value, &status, 0);
		free(full_cmd);
		full_cmd = NULL;
		free_array_of_str(cmd);

	}

	return (WEXITSTATUS(status));
}

/**
 * tokenize - it splits the line ito single words.
 *
 * @line: the line to be tokenized.
 * Return: the tokenization.
 */

char **tokenize(char *line)
{
	char *token = NULL, *linedup = NULL, **commands = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	linedup = _strdup(line);
	token = strtok(line, DELIM);
	if (token == NULL)
	{
		free(line);
		free(linedup);
		line = NULL;
		linedup = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(line);
	line = NULL;
	commands = malloc(sizeof(char *) * (count + 1));
	if (!commands)
	{
		free(linedup);
		linedup = NULL;
		return (NULL);
	}
	token = strtok(linedup, DELIM);
	while (token)
	{
		commands[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	commands[i] = NULL;
	free(linedup);
	linedup = NULL;
	return (commands);
}

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
