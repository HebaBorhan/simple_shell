#include "new_shell.h"

/**
 * _strlen - returns the length of a string
 * @string: the string to be checked
 * Return: length of the string
 */
int _strlen(const char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return (length);
}

/**
 * *_strncpy - copies a string
 * @dest: string to copy on
 * @src: string to be copied
 * @n: maximum number of characters to be copied
 *
 * Return: new copied string
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';

		i++;
	}

	return (dest);
}

void remove_line(char *command, char **lineremoved)
{
    int len;
    
    len = _strlen(command);
    
    *lineremoved = malloc(sizeof(char) * (len + 1));
    
    *_strncpy(*lineremoved, command, len - 1);
}
