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
