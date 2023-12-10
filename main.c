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

	int stat = 0, ind = 0;
	(void) ac;

	while (1)
	{
		line = read__line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		ind++;

		commd = _tokenizer(line);
		if (!commd)
			continue;

		stat = execute(commd, argv, ind);
	}
}
