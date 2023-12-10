#include "shell.h"
/**
 * stringdup - duplicate string
 * @s: the string to dup
 *
 * Return: the duplicated str
*/
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

/**
 * stringcmp - comparison of 2 str
 * @str1: first str
 * @str2: second str
 *
 * Return: -1 if str1 < str2 or the opposite
*/

int stringcmp(char *str1, char *str2)
{
	int cpt;

	cpt = (int)*str1 - (int)*str2;

	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		cpt = (int)*str1 - (int)*str2;
	}
	return (cpt);
}

/**
 * stringlen - the length of string
 * @str: the string
 *
 * Return: int length
*/

int stringlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

/**
 * stringcat - concatenate 2 strings
 * @dst: destination
 * @src: source
 *
 * Return: pointer to dst buf
*/

char *stringcat(char *dst, char *src)
{
	char *c = dst;

	while (*c)
		c++;

	while (*src)
	{
		*c = *src;
		c++;
		src++;
	}
	*c = *src;
	return (dst);
}

/**
 * stringcpy - strings copie
 * @dst: destination
 * @src: source
 *
 * Return: pointer to dest
*/

char *stringcpy(char *dst, char *src)
{
	int j = 0;

	while (src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = 0;
	return (dst);
}
