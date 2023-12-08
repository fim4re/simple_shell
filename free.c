#include "shell.h"

/**
 * freearray - function that free array
 * @array: the array that be free
 *
 * Return: free seccuss
*/

void freearray(char **array)
{
	int j;

	if (!array)
		return;
	for (j = 0; array[j]; j++)
	{
		free(array[j]);
		array[j] = NULL;
	}
	free(array), array = NULL;
}
/**
 * print_err - print error
 * @n: argument victor
 * @commd: command line
 * @ind: index
 *
 * Return: message error
*/

void print_err(char *n, char *commd, int ind)
{
	char *indx;
	char msg[] = ": not found\n";

	indx = intoa(ind);

	write(STDERR_FILENO, n, stringlen(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indx, stringlen(indx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, commd, stringlen(commd));
	write(STDERR_FILENO, msg, stringlen(msg));

	free(indx);
}

/**
 * intoa - convert a int to string
 * @c: int
 *
 * Return: int converted
*/

char *intoa(int c)
{
	char buf[20];
	int j = 0;

	if (c == 0)
		buf[j++] = '0';
	else
	{
		while (c > 0)
		{
			buf[j++] = (c % 10) + '0';
			c /= 10;
		}
	}
	buf[j] = '\0';
	reverse(buf, j);

	return (stringdup(buf));
}
/**
 * reverse - reverse the string
 * @s: string
 * @len: length of string
 *
 * Return: string reversed
*/

void reverse(char *s, int len)
{
	char td;
	int last = len - 1, fst = 0;

	while (fst < last)
	{
		td = s[fst];
		s[fst] = s[last];
		s[last] = td;
		fst++;
		last--;
	}
}
