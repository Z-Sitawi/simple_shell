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
	char *full_cmd;

	full_cmd = get_path(cmd[0]);
	if (!full_cmd)
	{
		show_error():
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
