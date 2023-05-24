#include "shell.h"

/**
 * non_int_mode - handles when user input in non interactive mode
 *
 * @envp: envrionmental variables
 * @cmd_args: program command string buffer.
 */


void non_int_mode(char **cmd_args, char **envp)
{/* Declaration of Variables */
	char *line = NULL, **args = NULL;
	size_t len;
	ssize_t nr_size;

/* Code Statements */
	while ((nr_size = getline(&line, &len, stdin)) != -1)
	{/* Successful Read */
		line[nr_size - 1] = '\0';/* Remove trailing newline */
		args = tokenize(line);
		if (!args[0])
		{
			free(args); }
		else
		{
			execute_command(args, cmd_args, envp); }
		free(line);
		len = 0;
	}
}

