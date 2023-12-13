#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strdup(char *str);
void remove_newline(char *input);
/*void freemalloc(char *arg);*/
void freemalloc2d(char **arg);
char *interpreter();
char **tokenizer(char *cmd);
int execution(char **args, char **argv);


#endif
