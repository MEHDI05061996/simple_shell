#include "shell.h"

/**
 * main- Entry point.
 *
 * @argc: Number of arguments passed to main progam
 * @argv: character pointer to character strings passed to
 * main program
 *
 * Return: integer value representing exit status.
 */

int main(int __attribute__((unused))argc, char **argv)
{/* Declaration of Variables */
	char **env = NULL;

/* Code Statements */
	env = fill_envp(argv);
	if (isatty(STDIN_FILENO))
	{/* reprompt if in interactive shell */
		prompt(argv, env); }
	else
	{
		non_int_mode(argv, env); }
	free(env);
	return (EXIT_SUCCESS);
}
