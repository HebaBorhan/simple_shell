#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * *interpreter - function that reads user input
 * Return: cmd
*/

char *interpreter()
{
char *cmd = NULL;
size_t n = 0;
ssize_t input;

    if (isatty(STDIN_FILENO)) 
       write(STDOUT_FILENO, "$ ",3);
    input = getline(&cmd, &n, stdin);
    if (input == -1)
    {
        write(STDOUT_FILENO, "\n", 1);
        free(cmd);
        exit(1);
    }
    remove_newline(cmd);
    if (_strcmp(cmd, "exit") == 0) 
    {
        exit(1);
    }


return(cmd);
}

/**
 * execution - function that parse and excute commands
 * @cmd: command to be parsed and executed
 * Return: void
*/

void execution(char *cmd)
{
    pid_t pid;
    char **args = NULL;
if (access(cmd, X_OK) == 0) {
         pid = fork();
         if (pid == -1) 
         {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) 
        {
            args = malloc(2 * sizeof(char));
            if (args == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            args[0] = cmd;
            args[1] = NULL;
            execve(cmd, args, NULL);           
            perror("execve");
            free(args);
            exit(EXIT_FAILURE);
        } else {            
            wait(NULL); 
        }
    } else {
        write(STDOUT_FILENO, "./shell: Command not found\n", 27);
    }
}

