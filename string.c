#include "shell.h"

char *stringdup(const char *s)
{
	char *ret;
	int length = 0, i;

	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		length++;
		s++;
	}
	s = s - length;
	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		ret[i] = s[i];
	return (ret);
}
