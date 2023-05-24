#include "shell.h"

/**
 * execute_command - Function that takes command line arguments and
 * executes them.
 *
 * @args: Charachter pointer to buffer containing tokenized arguments
 * @envp: Character pointer to buffer containing environmental variables.
 * @argv: Character pointer array to buffer holding program command string.
 */

void execute_command(char **args, char *argv[])
{/* Declaration of Variables */
	char *command = NULL, **env = NULL;
	int status = 0;

	env = fill_envp(&argv[0]);
	status = handle_built_ins(args, &argv[0], env);
	if (status == 0 || status == 2)
	{/* Check for built-in commands */
		free_envp(env);
		return; }
	command = handle_path(args, &argv[0]);
	if (!command)
	{/* Check for PATH commands */
		if (isatty(STDIN_FILENO))
		{
			handle_errors(&argv[0]);
			return; }
		return; }
	child_fork(args, &argv[0], command, env);
	if (_strcmp(args[0], command) != 0)
	{
		free(command); }
	free_envp(env);
}
