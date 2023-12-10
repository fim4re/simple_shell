#include "shell.h"

/***/

int _builtin(char *commd)
{
	char *bln[] = { "env", "exit", NULL};
	int j;

	for (j = 0; bln[j]; j++)
	{
		if (stringcmp(commd, bln[j]) == 0)
			return (1);
	}
	return (0);
}
void h_builtin(char **commd, char **argv, int *stat, int ind)
{
	(void) argv;
	(void) ind;

	if (stringcmp(commd[0], "env") == 0)
		_env(commd, stat);

	else if (stringcmp(commd[0], "exit") == 0)
		sh_exit(commd, stat);
}
void _env(char **commd, int *stat)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], stringlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(commd);
	(*stat) = 0;
}

void sh_exit(char **commd, int *stat)
{
	freearray(commd);
	exit(*stat);
}
