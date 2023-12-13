#include "new_shell.h"

/**
 * main - program to run a simple shell
 * @argc: arguments number
 * @argv: null terminated array of arguments
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	extern char **environ;
	size_t n = 1;
	char *lineremoved = NULL;
	char *command = NULL;
	char *delim = " ";
	char *token = NULL;
	char **toks = NULL;
	pid_t pid;
	int i, j;
	int status = 0;
	ssize_t user_input;
	(void) argc;
	
	/**
	 * char *cmd_path = NULL;
	 */

	i = 0;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, "$ ", 2);
			user_input = getline(&command, &n, stdin);

			/**
			 * Check for end of file (Ctrl+D)
			 */
			if (user_input == -1)
			{
				write(1, "\n", 1);
				if (command != NULL)
				{
					free(command);
					command = NULL;
				}
				close(STDOUT_FILENO);
				return(status);
				break;
			}
			/**
			 * remove the \n from command
			 */
			remove_line(command, &lineremoved);

			/**
			 * split tokens
			 */
			toks = malloc(sizeof(char *) * 1024);
			if (toks == NULL)
				return (-1);

			token = strtok(lineremoved, delim);
			i = 0;
			while (token)
			{
				toks[i] = strdup(token);

				if (toks[i] == NULL)
				{
					/**
					 * Handle allocation failure
					 */
					for (j = 0; j < i; j++)
					{
						free(toks[j]);
					}
					free(toks);
					return (-1);
				}

				token = strtok(NULL, delim);
				i++;
			}

			toks[i] = NULL;

			/**
			 * handle path
			 * and search for the command in path before fork
			 *cmd_path = search_path(toks);
			 *if (cmd_path != NULL){
			 *correct test
				printf("Command path: %s\n", cmd_path);
				*/

				pid = fork();
				if (pid == -1)
				{
					printf("Error in fork system call.\n");
					exit(1);
				}
				if (pid == 0)
				{

					printf("Freed memory\n");

					if (execve(toks[0], toks, environ) == -1)
					{
						perror(argv[0]);
					}
					printf("After execve\n");
					free(toks);
					exit(1);
				}
				else
				{
					/**
					 * Parent process
					 */
					wait(&status);
				}
				free(toks);
			/**
			else
			{
				printf("Error HERE");
			}
			*/
		}
		printf("HERE");
	}
	else
	{
		getline(&command, &n, stdin);
		printf("%s", command);
	}

	if (command != NULL)
	{
		free(command);
		command = NULL;
	}
	free(lineremoved);	
	free(toks);

	return (0);
}
