#include "shell.h"
/**
 * main - entry point
 * @ac: argument count
 * @argv: arg vector
 *
 * Return: on success 0, on error 1
*/

int main(int ac, char **argv)
{
	char *line = NULL;
	char **commd = NULL;

	int stat = 0, i;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = read__line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		commd = _tokenizer(line);
		if (!commd)
			continue;
		for (i = 0; commd[i]; i++)
		{
			printf("%s\n", commd[i]);
			free(commd[i]), commd[i] = NULL;
		}
		free(commd), commd = NULL;
	}
}
