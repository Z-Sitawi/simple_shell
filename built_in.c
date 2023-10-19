#include "main.h"
/**
 * check_builtin - checks if the command is built-in
 * @cmd: the cmd array
 *
 * Return: 1 if yes, 0 if no
 */
int check_builtin(char *cmd)
{
	int index;
	char *bltin_list[] = {"exit", "env", NULL};

	for (index = 0; bltin_list[index]; index++)
	{
		if (_strcomp(bltin_list[index], cmd) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * exec_builtin - handle the built-in commands
 * @cmd: command tokens
 * @status: the status
 * @av: the args vector
 * @index: index to use after
 */
void exec_builtin(char **cmd, int status, char **av, int index)
{
	(void) av;
	(void) index;

	if (_strcomp(cmd[0], "exit") == 0)
		my_exit(cmd, status);
	if (_strcomp(cmd[0], "env") == 0)
		my_env(cmd, status);
}

/**
 * my_exit - exit the shell
 * @cmd: command tokens
 * @stat: the status
 */
void my_exit(char **cmd, int stat)
{
	free_array_of_str(cmd);
	exit(stat);
}

/**
 * my_env - display the env content
 * @stat: the status
 * @cmd: commands array
 */
void my_env(char **cmd, int stat)
{
	int index;

	(void) stat;
	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array_of_str(cmd);
}
