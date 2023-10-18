#include "main.h"
/**
 * free_array_of_str - Frees and array of strings.
 * @aos: the array of strings to be freed.
 */

void free_array_of_str(char **aos)
{
	int i = 0;

	while (aos[i] != NULL)
	{
		free(aos[i]);
		aos[i] = NULL;
		i++;
	}

	free(aos);
	aos = NULL;
}
