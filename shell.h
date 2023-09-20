#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;
void free_arr(char **ary);
int _execute(char **command, char **argv, int ind);
char **tokenizer(char *line);
char *read_line(void);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void out_error(char *nombre, char *command, int ind);

char *_getenvii(char *varr);
char *_fetchpath(char *command);

void exitin(char **command, int status);

char *_itoa(int n);
void rev_str(char *str, int len);

int main(int ac, char **argv);

char **tokenizer(char *line);

void tokenize_line(char *line, char **command);

int count_tokens(char *line);
char **allocate_command_array(int count);

void exitin(char **command, int status);
int builtin_check(char *command);
void builtin_hnd(char **command, char **argv, int status, int ind);
void out_env(char **command, int status);

#endif