#include "new_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - program to run a simple shell
 * @argc: arguments number
 * @argv: null terminated array of arguments
 * Return: 0 (Success)
*/

int main(int argc, char *argv[])
{
    extern char **environ;
    char *lineremoved = NULL;
    ssize_t user_input;
    size_t n;
    char *cmd = NULL, *toks = NULL;
    pid_t pid;
    int status;

    //int i = 0;
    if (isatty(STDIN_FILENO))
    {
        while (1)
        {
            write(1, "$ ", 2);
            user_input = getline(&cmd, &n, stdin);

            if (user_input == -1)
            {
                return (-1);
           }
            toks = malloc(sizeof(char) * user_input);
            toks = input(cmd, n, user_input);
            if (toks == NULL)
            {
                perror("Error");
                return (-1);
            }
                        
            pid = fork();
            if (pid == -1)
            {
                printf("Error in fork system call.\n");
                exit(1);
            }
            if (pid == 0)
            {
                if (execve(&toks[0], &toks, environ) == -1)
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
       
    }
    else
    {
        getline(&cmd, &n, stdin);
        printf("%s", cmd);
    }
    free(cmd);
    free (toks);
    free(lineremoved);
    return (0);
}
