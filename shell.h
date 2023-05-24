#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

#define BUFSIZE 8192
#define MAX_COMMAND_LENGTH 2048
#define PROMPT "($) "
#define MAX_LINE_LENGTH 2048
#define MAX_PATH_LENGTH 4096
#define MAX_NUM_PATHS 128
#define MAX_ARGS 32
#define MAX_ARG_LENGTH 256


/*
 *File: shell.h
 *
 *Desc: Header file containing declarations for all function
 */

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */

typedef struct list
{
	char *var;
	struct list *next;

} list_t;


/* environment variables */
extern char **environ;

/* Function prototypes */
char **fill_envp(char **envp);
char **tokenize(char *command);
void execute_command(char **args, char **argv, char **envp);
int *prompt(char *cmd_args[], char **envp);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void handle_errors(char *cmd_args[]);
char *_getenv(char *name);
void sigint_handler(int sig);
void non_int_mode(char **cmd_args, char **envp);
int is_env_builtin(char *command);
int check_path(const char *command, char **path, char *full_path);
void exit_shell(void);
int handle_built_ins(char **args, char **argv, char **envp);
char **tokenize_path(char **argv);
char *handle_path(char **args, char **argv);
void child_fork(char **args, char *argv[], char **envp, char *cmd);

/* String Handlers */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strcspn(const char *s, const char *reject);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);

#endif /* SHELL_H */

