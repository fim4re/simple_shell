#include "shell.h"
/**
 * get_path - handle the path
 * @commd: command to handle
 *
 * Return: path commmand
*/

char *get_path(char *commd)
{
	int j;
	char *p_env, *f_commd, *d;
	struct stat s;

	for (j = 0; commd[j]; j++)
	{
		if (commd[j] == '/')
		{
			if (stat(commd, &s) == 0)
				return (stringdup(commd));
			else
				return (NULL);
		}
	}

	p_env = get_env("PATH");
	if (!p_env)
		return (NULL);

	d = strtok(p_env, ":");
	while (d)
	{
		f_commd = malloc(stringlen(d) + stringlen(commd) + 2);
		if (f_commd)
		{
			stringcpy(f_commd, d);
			stringcat(f_commd, "/");
			stringcat(f_commd, commd);
			if (stat(f_commd, &s) == 0)
			{
				free(p_env);
				return (f_commd);
			}
			free(f_commd), f_commd = NULL;
			d = strtok(NULL, ":");
		}
	}
	free(p_env);
	return (NULL);
}
