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

extern char **environ;

int _builtin(char *commd);
void h_builtin(char **commd, char **argv, int *stat, int ind);
void _env(char **commd, int *stat);
void sh_exit(char **commd, int *stat);

char *read__line(void);
char **_tokenizer(char *line);
void freearray(char **array);

char *stringdup(const char *s);
int stringcmp(char *str1, char *str2);
int stringlen(char *str);
char *stringcat(char *dst, char *src);
char *stringcpy(char *dst, char *src);
int execute(char **commd, char **argv, int ind);
char *get_env(char *var);
char *get_path(char *commd);
char *intoa(int c);
void reverse(char *s, int len);
void print_err(char *n, char *commd, int ind);


#endif
