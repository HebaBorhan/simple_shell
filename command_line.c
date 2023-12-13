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
       write(STDOUT_FILENO, "$ ",2);
    input = getline(&cmd, &n, stdin);
    if (input == -1)
    {
        free(cmd);
        return (NULL);
    }
   /* remove_newline(cmd);*/
    /*if (_strcmp(cmd, "exit") == 0) 
    {
        exit(1);
    }*/
return(cmd);
}

/**
 * **tokenization - function that parse and tokenize the command
 * @cmd: command to be parsed and tokinize
 * Return: void
*/
char **tokenization(char *cmd)
{
    char *cmdcpy = NULL, *token = NULL;
    const char *delim = " \t\n";
    char **args = NULL;
    int i = 1, j =0;

    
    if (cmd == NULL)
        return (NULL);
    
    cmdcpy = _strdup(cmd);
    token = strtok(cmdcpy, delim);
    while(token)
    {
        i++;
        token = strtok(NULL, delim);
    }
    args = malloc(sizeof(char *) * (i + 1));

    if (args == NULL)
    {
        free(cmd);
        return (NULL);
    }
    token = strtok(cmd, delim);
        
    while (token)
    {
        args[j] = _strdup(token); 
        token = strtok(NULL, delim);
        j++;
    }
    args[j] = NULL;
    free(cmdcpy);
    free(cmd);
   return (args);
}

/**
 * execution - function that parse and excute commands
 * @cmd: command to be parsed and executed
 * Return: void
*/

int execution(char **args, char **argv)
{
    pid_t pid;
    int status = 0;

    /*if (access(args, X_OK) == 0)*/
    
         pid = fork();
         /*if (pid == -1) 
         {
            perror("fork");
            return(-1);
         }*/
        if (pid == 0) 
        {
            if (execve(args[0], args, environ) == -1)
				{
					perror(argv[0]);
                    freemalloc2d(args);
                    exit(1);
				}
            }
                     
        else 
        {            
            waitpid(pid, &status, 0); 
            freemalloc2d(args);
        }
    

    return (WEXITSTATUS(status));
}
