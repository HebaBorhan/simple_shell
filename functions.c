#include "simple_shell.h"
/**
* _strlen - function that returns the length of a string.
* @s: The string to be checked
* Return: length
*/
int _strlen(char *s)
{
int length = 0;
while (*s != '\0')
{
length++;
s++;
}
return (length);
}


/**
* *_strcpy - function that copies the string pointed to by src,
* including the terminating null byte (\0), to the buffer pointed to by dest.
* @dest: buffer to copied to
* @src: string to be copied
* Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;
int j = 0;
while (*(src + i) != '\0')
{
i++;
}
for (; j < i; j++)
{
dest[j] = src[j];
}
dest[i] = '\0';
return (dest);
}

/**
* *_strchr - function that locates a character in a string
* @s: string to be checked
* @c: character we are looking for
* Return: &s[i] or '\0' (NULL - not found)
*/
char *_strchr(char *s, char c)
{
int i;
for (i = 0; s[i] >= '\0'; i++)
{
if (s[i] == c)
{
return (&s[i]);
}
}
return ('\0');
}

/**
* _strcmp - function that compares 2 strings.
* @s1: The string to be compared.
* @s2: The string to be compared.
* Return: s1[i] - s2[i]
*/
int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}
return (0);
}

/**
* remove_newline - function that removes new line
* @input: string to be checked
* Return: void
*/
void remove_newline(char *input) 
{
    char *newline_ptr = _strchr(input, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }
}
