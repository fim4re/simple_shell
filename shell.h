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

extern char ** envr;

char *read__line(void);
char **_tokenizer(char *line);
void freearray(char **array);

char *stringdup(const char *s);
int stringcmp(char *str1, char *str2);
int stringlen(char *str);
char *stringcat(char *dst, char *src);
char *stringcpy(char *dst, char *src);
int execute(char **commd, char ** argv);

#endif
