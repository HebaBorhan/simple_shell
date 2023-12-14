#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * **tokenization - function that parse and tokenize the command
 * @cmd: command to be parsed and tokinize
 * Return: char
 */
char **tokenization(char *cmd)
{
	char *cmdcpy = NULL, *token = NULL;
	const char *delim = " \t\n";
	char **args = NULL;
	int i, j;

	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}
	cmdcpy = _strdup(cmd);
	token = strtok(cmd, delim);
	for (i = 1; token != NULL; i++)
		token = strtok(NULL, delim);
	free(cmd);
	cmd = NULL;
	args = malloc(sizeof(char *) * (i + 1));
	if (args == NULL)
	{
		free(cmdcpy);
		free(args);
		return (NULL);
	}
	token = strtok(cmdcpy, delim);
	if (token == NULL)
	{
		free(cmdcpy);
		free(args);
		return (NULL);
	}
	while (token)
	{
		args[j] = _strdup(token);
		token = strtok(NULL, delim);
		j++;
	}
	free(cmdcpy);
	cmdcpy = NULL;
	args[j] = NULL;
	return (args);
}
