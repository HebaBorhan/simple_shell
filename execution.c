#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
 * execution - function that parse and excute commands
 * @args: number of arguments
 * @argv: value of args
 * Return: int
 */
int execution(char **args, char **argv)
{
	pid_t pid;
	int status = 0;

	if (args == NULL || args[0] == NULL)
		return (0);
	if (_strcmp(args[0], "exit") == 0)
	{
		freemalloc2d(args);
		exit(0);
	}
	if (args[0] != NULL && _strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
			freemalloc2d(args);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		freemalloc2d(args);
	}
	return (WEXITSTATUS(status));
}
