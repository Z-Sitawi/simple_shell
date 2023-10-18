#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"


char *_strcpy(char *dest, char *src);

char *_strdup(char *str);	/* allocates memory dynamically "use free" */

size_t _strlen(char *s);

int execute_cmd(char **cmd, char **av, int index);

void free_array_of_str(char **aos);

char *readline(void);

char **tokenize(char *line);

int _strcomp(char *str1, char *str2);

char *_str_concat(char *dest, const char *src);

char *get_env(char *enva);	/* allocates memory dynamically "use free" */

char *get_path(char *cmd);	/* allocates memory dynamically "use free" */

extern char **environ;

char *reverse_str(char *str);

char *num_to_str(int num);	/* allocates memory dynamically "use free" */

void display_error(char *pname, char *cmd, int index);
#endif
