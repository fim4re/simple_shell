#include "shell.h"
/**
 * get_env - fuction that get environ
 * @var: the command to get env
 *
 * Return: env
*/

char *get_env(char *var)
{
	char *td, *key, *val, *ev;
	int j;

	for (j = 0, environ[j]; j++)
	{
		td = stringdup(environ[j]);
		key = strtok(td, "=");
		if (stringcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			ev = stringdup(val);
			free(td);
			return (ev);
		}
		free(td), td = NULL;
	}
	return (NULL);
}
