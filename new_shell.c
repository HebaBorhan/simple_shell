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
	char *lineremaoved = NULL;
	char *buffer = NULL;
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
			printf("$ ");
			getline(&buffer, &n, stdin);
			/**
			 * remove the \n from buffer
			 * then split tokens
			 */
			len = strlen(buffer);
			lineremaoved = malloc(sizeof(char) * len + 1);
			strncpy(lineremaoved, buffer, len - 1);
			toks = malloc(sizeof(char *) * 1024);
			if (toks == NULL)
				return (-1);
			token = strtok(lineremaoved, delim);
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
				printf("Before execve\n");
				if (execve(toks[0], toks, environ) == -1)
				{
					perror(argv[0]);
				}
				printf("After execve\n");
			}

			else
			{
				// Parent process
				do
				{
					pid_t w = waitpid(pid, &status, WUNTRACED);
					if (w == -1)
					{
						perror("waitpid");
						exit(EXIT_FAILURE);
					}
					if (WIFEXITED(status))
					{
						printf("Child has exited with status %d.\n", WEXITSTATUS(status));
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed by signal %d.\n", WTERMSIG(status));
					}
					else if (WIFSTOPPED(status))
					{
						printf("Child has been stopped by signal %d.\n", WSTOPSIG(status));
					}
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}

			free(buffer);
		}
		printf("HERE");
	}
	else
	{
		getline(&buffer, &n, stdin);
		printf("%s", buffer);
	}
	return (0);
}
