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

char *_strdup(char *str);

size_t _strlen(char *s);

int execute_cmd(char **cmd, char **av);

void free_array_of_str(char **aos);

char *readline(void);

char **tokenize(char *line);




extern char **environ;

#endif
