#include "new_shell.h"

char *search_path(char **args)
{
    char *path = getenv("PATH");
    char *tok = strtok(path, ":");
    char cmd[1024] = {0};
    struct stat statbuf;

    while (tok != NULL)
    {
        _strncpy(cmd, tok, sizeof(cmd)); // Copy the tok string to cmd
        
        cmd[sizeof(cmd) - 1] = '\0';
        
        strcat(cmd, "/");
        strcat(cmd, args[0]);
        if (stat(cmd, &statbuf) == 0 && S_ISREG(statbuf.st_mode))
        {
            printf("Command found at path: %s\n", cmd);
            return strdup(cmd); // return a copy of the command path
        }

        tok = strtok(NULL, ":");
    }

    return NULL; // return NULL if the command is not found
}
