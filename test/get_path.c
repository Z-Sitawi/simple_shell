#include "main.h"
/**
 * get_path - It gets the full path of a cmd.
 *
 * @cmd: The enterd cmd.
 */

char *get_path(char *cmd)
{
	char *path_val, *full_path, *folder;
	struct stat st;

	path_val = get_env("PATH");

	folder = strtok(path_val, ":");
	while (folder != NULL)
	{
		/* size = (folder len) + "/" + (command len) + "\0" */
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

}
