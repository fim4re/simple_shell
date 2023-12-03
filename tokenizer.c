#include "shell.h"

/**
 * _tokenizer - tokenizer a line command
 * @line: the line
 *
 * Return: command line
*/

char **_tokenizer(char *line)
{
	char *tokn = NULL, *td = NULL;
	int c = 0, i = 0;
	char **commd = NULL;

	if (!line)
		return (NULL);
	td = stringdup(line);

	tokn = strtok(td, DELIM);

	if (tokn == NULL)
	{
		free(line), line = NULL;
		free(td), td = NULL;
		return (NULL);
	}

	while (tokn)
	{
		c++;
		tokn = strtok(NULL, DELIM);
	}
	free(td), td = NULL;

	commd = malloc(sizeof(char *) * (c + 1));
	if (!commd)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tokn = strtok(line, DELIM);
	while (tokn)
	{
		commd[i] = stringdup(tokn);
		tokn = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	commd[i] = NULL;
	return (commd);
}
