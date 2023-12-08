#include "shell.h"

/**
 * execute - execute UNIX command line
 * @commd: command line
 * @argv: argument vector
 * @ind: index
 *
 * Return: line command
*/

int execute(char **commd, char **argv, int ind)
{
	pid_t ch;
	int stat;
	char *f_commd;

	f_commd = get_path(commd[0]);
	if (!f_commd)
	{
		print_err(argv[0], commd[0], ind);
		freearray(commd);
		return (127);

	}

	ch = fork();
	if (ch == 0)
	{
		if (execve(f_commd, commd, environ) == -1)
		{
			free(f_commd), f_commd = NULL;
			freearray(commd);
		}
	}
	else
	{
		waitpid(ch, &stat, 0);
		freearray(commd);
		free(f_commd), f_commd = NULL;
	}
	return (WEXITSTATUS(stat));
}
