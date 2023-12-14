#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * *interpreter - function that reads user input
 * Return: cmd
 */

char *interpreter(void)
{
char *cmd = NULL;
size_t n = 0;
ssize_t input;

if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);

input = getline(&cmd, &n, stdin);
if (input == -1)
{
	free(cmd);
	return (NULL);
}

    /**
     * remove_newline(cmd);
     */

    /**
     * if (_strcmp(cmd, "exit") == 0)
     * {
     * exit(1);
     * }
     */
return (cmd);
}
