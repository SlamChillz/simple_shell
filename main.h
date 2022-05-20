#ifndef SHELL_H
#define SHELL_H

#define BUFFERSIZE 1024	  /* size of buffer memory */
#define DELIMS " :\t\r\n" /* delimeters */
#define STATUS 0	  /* exit status */

extern char **environ;

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>
#include <signal.h>

void int_mode(char **argv);
void nonint(char **argv);
int _intlen(int n);
int _strlen(char *s);
void _reverse(char *s);
char *_itoa(unsigned int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *copy(char *str, int n);
char *join(char *s1, char *s2, char *str3);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);

int _isalpha(int c);
int _atoi(char *s);

ssize_t _getline(char **line, size_t *n, FILE *stream);
void hashtag(char *buff);
char *rem_(char *str);
char *rem_spe(char *str);
int _strcount(char *str);
char **tokenise(char *str);

void _xit(char *in, char **argv, char **tokens, int n);
int env(char **tokens, int *stat);
int _setenv(char **tokens, int *stat);
int _unsetenv(char **tokens, int *stat);
char *_getenv(char *var);
int _chdir(char **tokens, int *stat);
int _execbuiltins(char **tokens, int *stat);
int path(char **token, int loop);
int checkoperand(char *str);
char **cut(char **token, int n);
void run(char **token, int *prev, char *op, int loop);
int echocheck(char *str);
int _echo(char **token, int *status);
int _execpath(char **token, int loop, int *status);
int execute(char **tokens, int loop);
int batch_mode(char *filename);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearray(char **array);

int _putchar(char c);
void prompt(void);
void print(char *s);
void _printf(char *s);
void signal_handr(int signum);
void printerror(char *in, char *name, int loop);
void exiterror(char **argv, char **tokens, int loop);
typedef void (*sighandler_t)(int);

/**
 * struct builtin - structure for custom built in functions
 * @name: string, name of the builtin
 * @func: pointer to a function to execute
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **, int *);
} builtin;

#endif /* SHELL */

