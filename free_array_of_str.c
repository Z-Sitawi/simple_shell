#include "main.h"
/**
 * free_array_of_str - Frees and array of strings.
 * @aos: the array of strings to be freed.
 */

void free_array_of_str(char **aos)
{
	int i;

	if (aos == NULL)
	{
		return;
	}

	for (i = 0; aos[i] != NULL; i++)
	{
		free(aos[i]);
	}

	free(aos);
}
