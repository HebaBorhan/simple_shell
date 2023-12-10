#include "new_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * *input - function that simulates command line
 * @cmd: pointer to buffer of the entered comand
 * @n: size of the buffer
 * @user_input: number of characters resulted from getline
 * Return: args
*/

char *input(char *cmd, size_t n, ssize_t user_input)
{

char *cmd_cpy = NULL;
char *delim = " \n";
char *token = NULL, **args = NULL;
int len, i = 0;
    
len = _strlen(cmd);
cmd_cpy = malloc(sizeof(char) * user_input);
    
    if (cmd_cpy == NULL)
    {
        perror("Error");
        return (NULL);
    }
_strncpy(cmd_cpy, cmd, len - 1);

            token = strtok(cmd, delim);
            while(token)
            {
                token = strtok(NULL, delim);
                i++;
            }
            args = malloc(sizeof(char) * i);
            token = strtok(cmd_cpy, delim);
            i = 0;
            while(token)
            {
                args[i] = token;
                token = strtok(NULL, delim);
                i++;
            }
            args[i] = NULL;
    free (cmd_cpy);
    
    return (*args);
}

