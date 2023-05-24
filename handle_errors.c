#include "shell.h"

/**
 * handle_errors - Function that handles error.
 *
 * @cmd_args: character pointer array of program arguments.
 */

void handle_errors(char *cmd_args[])
{
	perror(cmd_args[0]);
}
