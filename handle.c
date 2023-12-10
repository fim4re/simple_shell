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
	char *p_env, *f_commd, *dr;
	char *ev = get_env("PATH");
	struct stat s;

	for (j = 0; commd[j]; j++)
	{
		if (commd[j] == '/')
		{
			if (stat(commd, &s) == 0)
				return (stringdup(commd));

			return (NULL);
		}
	}

	p_env = ev;
	if (!p_env)
		return (NULL);

	dr = strtok(p_env, ":");
	while (dr)
	{
		f_commd = (char*)malloc(stringlen(dr) + stringlen(commd) + 2);
		if (f_commd)
		{
			stringcpy(f_commd, dr);
			stringcat(f_commd, "/");
			stringcat(f_commd, commd);
			if (stat(f_commd, &s) == 0)
			{
				free(p_env);
				return (f_commd);
			}
			free(f_commd), f_commd = NULL;

			dr = strtok(NULL, ":");
		}
	}
	free(p_env);
	return (NULL);
}
