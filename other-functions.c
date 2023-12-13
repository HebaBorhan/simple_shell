#include "simple_shell.h"
#include <stdlib.h>
/**
* *_strdup - function that returns a pointer to a newly allocated
* space in memory,
* which contains a copy of the string given as a parameter.
* @str: string to be dublicated
* Return: pointer to duplicated string,
* or NULL if insufficient memory was available or str = NULL
*/
char *_strdup(char *str)
{
char *dupstr = NULL;
int counter = 0;
if (str == NULL)
{
return (NULL);
}
counter = _strlen(str);
dupstr = malloc(sizeof(char) * (counter + 1));
if (dupstr == NULL)
{
return (NULL);
}
_strcpy(dupstr, str);
return (dupstr);
}


/**
* remove_newline - function that removes new line
* @input: string to be checked
* Return: void
*/
void remove_newline(char *input) 
{
    char *newline_ptr = _strchr(input, '\n');
    if (newline_ptr != NULL) 
    {
        *newline_ptr = '\0';
    }
}

/**
* freemalloc - function that free memory allocation
* @arg: string to be freed
* Return: void
*/

/*void freemalloc(char *arg)
{
    free(arg);
    arg = NULL;
}*/

/**
* freemalloc2d - function that free memory allocation
* @arg: array to be freed
* Return: void
*/

void freemalloc2d(char **arg)
{
    int i = 0;
    if (arg == NULL)
        return;
    while (arg[i] != NULL) {
        free(arg[i]);
        arg[i] = NULL;
        i++;
    }
    free(arg);
    arg = NULL;
}
