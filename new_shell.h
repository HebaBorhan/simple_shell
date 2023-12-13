#ifndef NEW_SHELL_H
#define NEW_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

int _strlen(const char *string);
void remove_line(char *command, char **lineremoved);
char *_strncpy(char *dest, const char *src, int n);

/**
 * char *input(char *cmd, size_t n, ssize_t user_input);
 */

/**
 * char *search_path(char **args);
 */

#endif
