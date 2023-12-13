#include "simple_shell.h" 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - program to run a simple shell
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 (Success)
*/

int main(int argc, char **argv)
{
char *cmd = NULL, **toks = NULL;
int stat = 0;
(void)argc;


    while (1) {
        cmd = interpreter(); 
        if (cmd == NULL)
        {
            if (isatty(STDIN_FILENO)) 
                write(STDOUT_FILENO, "\n",1);
            return (stat);
        }
        toks = tokenizer(cmd);
        if (toks == NULL)
            continue;
      

        stat = execution(toks, argv);
         /*if (stat == -1)
            continue;*/
    }
}
