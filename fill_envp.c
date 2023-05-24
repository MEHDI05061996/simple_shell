#include "shell.h"

/**
 * fill_envp - Function that initializes character
 * pointer with environment variables.
 *
 * @cargs: character pointer to buffers command line string.
 *
 * Return: character pointer to buffers updated with environmental
 * variables
 */

char **fill_envp(char **cargs)
{/* Declaration of Variables*/
	int env_count, i;
	char **set_env = NULL;

/* Code Statements */
	/* Allocate memory for envp */
	for (env_count = 0; environ[env_count] != NULL; env_count++)
	set_env = malloc((env_count + 1) * sizeof(char *));
	if (set_env == NULL)
	{
		handle_errors(&cargs[0]); }
	for (i = 0; environ[i] != NULL; i++)
	{
		set_env[i] = strdup(environ[i]); }
	set_env[i] = NULL; /* set last element to NULL for execve */
	return (set_env);
}
