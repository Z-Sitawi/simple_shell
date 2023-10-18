#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t read, _write;

	while (1) {
		write(STDOUT_FILENO, "$ ", 2); /* Print the prompt */
		fflush(stdout);
		read = getline(&line, &len, stdin);

		if (read == EOF) {
			/* End-of-file (Ctrl+D) or an error occurred */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove the newline character from the end of the line */
		if (line[read - 1] == '\n') {
			line[read - 1] = '\0';
		}
		if (strcmp(line, "exit") == 0) {
            break; /* Exit the shell */
        }
		/* Print the entered command */
		_write = write(STDOUT_FILENO, line, strlen(line));
		if (_write != 0)
			write(STDOUT_FILENO, "\n", 1);

	}


return 0;
}

