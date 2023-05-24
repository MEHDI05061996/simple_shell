#include "shell.h"

/**
 * handle_built_ins - Function that compares command line to
 * system built ins and executes if a match is found.
 *
 * @args: character pointer to buffers holding parsed command line arguments.
 * @argv: character pointer to buffers holding program arguments.
 * @envp: character pointer to buffers holding environmental variable values.
 *
 * Return: Integer value representing execution status.
 * (0 - Success), (1 - command not built in), (2 - Error)
 */

int handle_built_ins(char **args, char **argv, char **envp)
{/* Declaration of Variables */
	int j, p;
	const char *td;

/* Code Statements */
	if (_strcmp(args[0], "env") == 0)
	{/* check if command is "env" built-in */
		for (j = 0; envp[j] != NULL; j++)
		{
			write(STDOUT_FILENO, envp[j], _strlen(envp[j]));
			write(STDOUT_FILENO, "\n", 1); }
		return (0); }
	else if (_strcmp(args[0], "exit") == 0)
	{/* check if command is "exit" built-in */
		exit(EXIT_SUCCESS); }
	else if (_strcmp(args[0], "cd") == 0)
	{/* check if command is "cd" built-in */
		td = _getenv("HOME");
		if (args[1] == NULL)
		{
			chdir(td);
			return (0); }
		p = chdir(args[1]);
		if (p != 0)
		{
			if (isatty(STDIN_FILENO))
			{
				handle_errors(&argv[0]);
				return (2); }
		}
		return (0); }
	return (1);
}
