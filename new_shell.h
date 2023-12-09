#ifndef NEW_SHELL_H
#define NEW_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strlen(const char *string);
void remove_line(char *command, char **lineremoved);
char *_strncpy(char *dest, const char *src, int n);

#endif