#include "shell.h"

/**
 * execute - execute UNIX command line
 * @commd: command line
 * @argv: argument vector
 *
 * Return: line command
*/

int execute(char **commd, char **argv)
{
	pid_t ch;
	int stat;

	ch = fork();
	if (ch == 0)
	{
		if (execve(commd[0], commd, environ) == -1)
		{
			perror(argv[0]);
			freearray(commd);
			exit(0);
		}
	}
	else
	{
		waitpid(ch, &stat, 0);
		freearray(commd);
	}
	return (WEXITSTATUS(stat));
}
