#include "main.h"

/**
 * get_env -  retrieves the value of an environment variable.
 *
 * @enva: The environment variable.
 *
 * Return: The duplication of the value.
 */

char *get_env(char *enva)
{
	char *tmpv, *var, *value, *valdup;
	int x;

	for (x = 0; environ[x]; x++)
	{
		tmpv = _strdup(environ[x]);
		var = strtok(tmpv, "=");

		if (strcmp(enva, var) == 0)
		{
			value = strtok(NULL, "\n");
			valdup = _strdup(value);
			free(tmpv);
			tmpv = NULL;
			return (valdup);
		}
		free(tmpv);
		tmpv = NULL;
	}

	return (NULL);
}
