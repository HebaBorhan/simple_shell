#include "simple_shell.h"

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		size_t len = 0;

		while (environ[i][len] != '\0')
		{
			len++;
		}

		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
