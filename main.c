#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void display_prompt() {
    if (isatty(STDIN_FILENO)) {
        printf("#cisfun$ ");
        fflush(stdout);
    }
}

void execute_command(char *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        /* Child process */
        char *argv[2];
        argv[0] = command;
        argv[1] = NULL;

        /* Redirect standard output to the parent process (terminal) */
        if (dup2(STDOUT_FILENO, STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(1);
        }

        /* Close standard input (stdin) to prevent further input reading */
        close(STDIN_FILENO);

        if (execve(command, argv, NULL) == -1) {
            perror("execve");
            exit(1);
        }
    } else {
        /* Parent process */
        wait(&status);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break; /* End of file (Ctrl+D) was detected */
        }

        /* Remove newline character */
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break; /* Exit the shell */
        }
        execute_command(input);
    }

    return 0;
}

