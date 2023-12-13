#include "shell.h"

/**
 * _builtin - print builtin coommand
 * @commd: command line
 *
 * Return: 1 if command in, or 0
*/

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
/**
 * h_builtin - handle commande
 * @commd: commande
 * @argv: argument victor
 * @stat: last status
 * @ind: index
 *
 * Return: handle command
*/
void h_builtin(char **commd, char **argv, int *stat, int ind)
{
	(void) argv;
	(void) ind;

	if (stringcmp(commd[0], "env") == 0)
		_env(commd, stat);

	else if (stringcmp(commd[0], "exit") == 0)
		sh_exit(commd, stat);
}
/**
 * _env - fonction env
 * @commd: commande line
 * @stat: status
 *
 * Return: env commande
*/
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
/**
 * sh_exit - fonction to exit
 * @commd: commande
 * @stat: status
 *
 * Return: exit
*/
void sh_exit(char **commd, int *stat)
{
	freearray(commd);
	exit(*stat);
}
