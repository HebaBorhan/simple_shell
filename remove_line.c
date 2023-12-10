#include "new_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_line(char *command, char **lineremoved)
{
    int len;
    
    len = _strlen(command);
    
    *lineremoved = malloc(sizeof(char) * (len + 1));
    
    _strncpy(*lineremoved, command, len - 1);
}
