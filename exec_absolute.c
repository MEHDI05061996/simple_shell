#include "shell.h"

/**
 * execute_command - Function that takes command line arguments and
 * executes them.
 *
 * @args: Charachter pointer to buffer containing tokenized arguments
 * @envp: Character pointer to buffer containing environmental variables.
 * @argv: Character pointer array to buffer holding program command string.
 */

void execute_command(char **args, char *argv[], char **envp)
{/* Declaration of Variables */
	char *command = NULL;
	int status = 0;

	status = handle_built_ins(args, &argv[0], envp);
	if (status == 0 || status == 2)
	{/* Check for built-in commands */
		return; }
	command = handle_path(args, &argv[0]);
	if (!command)
	{/* Check for PATH commands */
		if (isatty(STDIN_FILENO))
		{
			free(args);
			handle_errors(&argv[0]); }
		else
		{
			free(args); }
		return; }
	child_fork(args, &argv[0], envp, command);
}
