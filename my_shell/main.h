#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/* string lib may removed after creating my own functions */
#include <string.h>
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int my_getchar();
ssize_t my_getline(char **line, size_t *n);

#endif
