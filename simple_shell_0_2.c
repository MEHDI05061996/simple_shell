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

/* Code Statements */
	if (isatty(STDIN_FILENO))
	{/* reprompt if in interactive shell */
		prompt(argv); }
	else
	{
		non_int_mode(argv); }
	return (EXIT_SUCCESS);
}
