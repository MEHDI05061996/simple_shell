#include "shell.h"

/**
 * prompt - Display the prompt and wait for user input
 *
 * @cmd_args: character pointer to buffers holding cmd arguments.
 * @envp: character pointer to buffers holding environmental variables.
 *
 * Return: Integer value representing exit status
 */

int *prompt(char **cmd_args, char **envp)
{/* Declaration of Variables */
	char **arg_s = NULL, *line = NULL;
	size_t len;
	ssize_t read_size;

	while (1)
	{/* Code Statements */
		signal(SIGINT, sigint_handler);
		fflush(stdout); /* Make sure prompt is displayed before input */
		write(STDOUT_FILENO, PROMPT, 4);
		read_size = getline(&line, &len, stdin);
		if (read_size != -1)
		{/* Successful Read */
			line[read_size - 1] = '\0';/* Remove trailing newline */
			arg_s = tokenize(line);
			if (!arg_s[0])
			{
				free(arg_s);
				continue; }
			execute_command(arg_s, cmd_args, envp); }
		else
		{/* Error occurred while reading */
			if (feof(stdin) == 0)
			{/* If end of file (Ctrl + D) */
				write(STDOUT_FILENO, "\n", 1);
				break; }
			if (errno != EINTR && errno != 0)
			{
				handle_errors(&cmd_args[0]);
				continue; }
			else if (errno == 0)
			{
				write(STDOUT_FILENO, "\n", 1);
				continue; }}}
	return (0);
}
