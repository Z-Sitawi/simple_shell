#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 128

void display_prompt() {
    if (isatty(STDIN_FILENO)) {
        printf("#cisfun$ ");
        fflush(stdout);
    }
}

void execute_command(char *command) {
    pid_t child_pid;
    int status;
    char *args[MAX_ARGS]; /* Array to hold command and its arguments */
    int arg_count = 0;

    /* Tokenize the command line into arguments */
    char *token = strtok(command, " \t\n");
    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " \t\n");
    }
    args[arg_count] = NULL; /* Null-terminate the array of arguments */

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        /* Child process */
        /* Redirect standard output to the parent process (terminal) */
        if (dup2(STDOUT_FILENO, STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(1);
        }

        /* Close standard input (stdin) to prevent further input reading */
        close(STDIN_FILENO);

        if (execve(args[0], args, NULL) == -1) {
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
