#include "main.h"

/**
 * display_error -  prints error message.
 *
 * @pname: The program name.
 * @cmd: the command entered.
 * @index: the index of the command.
 *
 */

void display_error(char *pname, char *cmd, int index)
{
	char *str_index, msg[] = ": not found\n";

	str_index = num_to_str(index);

	write(STDERR_FILENO, pname, _strlen(pname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(str_index);

}
