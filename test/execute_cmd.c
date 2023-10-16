#include "main.h"
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
