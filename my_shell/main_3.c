#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command) {
    pid_t child_pid;
    int status;

    if (access(command, F_OK) == -1) {
        perror("access");
        return;
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        char *argv[MAX_INPUT_SIZE];
        int i = 0;

        char *token = strtok(command, " ");
        while (token != NULL) {
            argv[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        argv[i] = NULL;

        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        wait(&status);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            execute_command(argv[i]);
        }
        return 0;
    }

    char *prompt = "(Eshell) $ ";
    char *lineptr = NULL;
    size_t n = 0;

    int interactive = isatty(STDIN_FILENO);

    while (1) {
        if (interactive) {
            printf("%s", prompt);
            fflush(stdout);
        }

        if (getline(&lineptr, &n, stdin) == -1) {
            if (interactive) {
                printf("Exit\n");
            }
            break;
        }

        size_t length = strlen(lineptr);
        if (length > 0 && lineptr[length - 1] == '\n') {
            lineptr[length - 1] = '\0';
        }

        if (strcmp(lineptr, "exit") == 0) {
            if (interactive) {
                printf("Exit\n");
            }
            break;
        }

        if (interactive || !interactive) {
            execute_command(lineptr);
        }
    }

    free(lineptr);
    return 0;
}

