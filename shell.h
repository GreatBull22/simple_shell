#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcnt1.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define BUFFER_SIZE 1024
#define MAX_TOKENS 1024
#define PROMPT "$"
#define PATH_SEPARTOR ":"
#define PATH_MAX_LENGTH 4096

/*prompt.c*/
void prompt(void);

/*get_input.c*/
void free_last_input(void);
char *get_input(void);
/*get_line.c*/
void *get_line(void);

/*built-in funcs*/
int shell_clear(char **args);
int shell_env(void);
int shell_unsetenv(char **args);
int shell_setenv(char **args);
void shell_cd(char **args);
void shell_exit(char **args);
void shell_help(void);
int execute_buitlin(char *cmd, char **args);
int check_for_builtin(char **args);

/*signal_handler.c*/
void handle_sigstp(int sig);
void handle_sigquit(int sig);
void handle_sigint(int sig);

/*execute.c*/
int execute(char **args);

/*parser.c*/
char **tokenize_input(char *input);
char **tokenize(char *str, const char *delim);

/*get_path.c*/
char *get_path(void);

/*find_in_path.c*/
char *find_in_path(char *command);

/*free.c*/
void free_path(void);
void free_tokens(char **ptr);
void free_error(char **argv, char *arg);

/*error.c*/
void _puterror(char *err);
void _puts(char *str);

/*utils_funcs1.c*/
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
int _strlen(cinst char*);

/*utils_funcs2.c*/
unsigned int _strspn(char *s, char *accept);
int _putchar(char);
char *_strdup(const char *);
char *_strcat(char *, const char *);
char *_strcpy(char *, char *);

/*utils_funcs3.c*/
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *, unsigned int, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
char *memset(char *, char, unsigned int);
int - atoi(const char *str);

#endif

