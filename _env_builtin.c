#include "shell.h"

/**
 * is_env_builtin - Check if command is "env" built-in
 *
 * @command: Character pointer to command line
 *
 * Return: 1 if command is "env", 0 otherwise
 */

int is_env_builtin(char *command)
{
	if (_strcmp(command, "env") == 0)
	{
		return (1);
	}
	return (0);
}
