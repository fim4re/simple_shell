#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"

char *read__line(void);
char **_tokenizer(char *line);

char *stringdup(const char *s);
int stringcmp(char *s1, char *s2);
int stringlen(char *s);
char *stringcat(char *dst, char *src);
char *stringcpy(char *dst, char *src);

#endif
