#include "main.h"
/**
 * get_path - It gets the full path of a cmd.
 *
 * @cmd: The enterd cmd.
 * Return: full path or NULL if fail.
 */

char *get_path(char *cmd)
{
	char *path_val, *full_path, *folder;
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path_val = get_env("PATH");
	if (!path_val)
		return (NULL);
	folder = strtok(path_val, ":");
	while (folder != NULL)
	{
		full_path = malloc(_strlen(folder) + _strlen(cmd) + 2);
		if (full_path)
		{
			_strcpy(full_path, folder);
			_str_concat(full_path, "/");
			_str_concat(full_path, cmd);

			if (stat(full_path, &st) == 0)
			{
				free(path_val;
				path_val = NULL;
				return (full_path);
			}
			free(full_path);
			full_path = NULL;
		}
	}
	free(path_val);
	return (NULL);
}
