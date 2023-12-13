#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
	extern char **environ;
	size_t n = 1;
	int len = 0;
	char *lineremoved = NULL;
	char *command = NULL;
	char *delim = " ";
	char *token = NULL;
	char **toks = NULL;
	pid_t pid;
	int status;

	int i = 0;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, "$ ", 2);
			ssize_t user_input = getline(&command, &n, stdin);

			// Check for end of file (Ctrl+D)
			if (user_input == -1)
			{
				printf("\n");
				break; // Exit the loop on EOF
			}
			/**
			 * remove the \n from command
			 * then split tokens
			 */
			remove_line();
			len = strlen(command);
			lineremoved = malloc(sizeof(char) * len + 1);
			strncpy(lineremoved, command, len - 1);
			
			toks = malloc(sizeof(char *) * 1024);
			if (toks == NULL)
				return (-1);
			
			token = strtok(lineremoved, delim);
			i = 0;
			while (token)
			{
				toks[i] = strdup(token);
				token = strtok(NULL, delim);
				i++;
			}
			/**
			 * handle path
			 * and search for the command in path before fork
			 */
			pid = fork();
			if (pid == -1)
			{
				printf("Error in fork system call.\n");
				exit(1);
			}
			if (pid == 0)
			{
				if (execve(toks[0], toks, environ) == -1)
				{
					perror(argv[0]);
				}
				printf("After execve\n");
			}

			else
			{
				// Parent process
				wait(&status);
			}
		}
		printf("HERE");
	}
	else
	{
		getline(&command, &n, stdin);
		printf("%s", command);
	}
	free(command);
	return (0);
}
