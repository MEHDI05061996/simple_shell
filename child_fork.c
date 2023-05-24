#include "shell.h"

/**
 * child_fork - Function that creates child process and executes command.
 *
 * @args: Charachter pointer to buffer containing tokenized arguments
 * @envp: Character pointer to buffer containing environmental variables.
 * @argv: Character pointer array to buffer holding program command string.
 * @cmd: Character pointer to parsed command.
 */

void child_fork(char **args, char *argv[], char **envp, char *cmd)
{/* Declaration of Variables */
	pid_t pid;
	int status = 0;

/* Code Statements */
	pid = fork();
	if (pid == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			free(args);
			handle_errors(&argv[0]); }
		else
		{
			free(args); }
			return; }
	else if (pid == 0)
	{/* Child process */
		if (isatty(STDIN_FILENO))
		{
			execve(cmd, args, envp);
			handle_errors(&argv[0]); }
		else
		{
			execve(cmd, args, envp); }}
	else
	{ /*Parent process - Wait for child process to complete */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status)); }
	free(args);
}
