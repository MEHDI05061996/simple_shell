#include "shell.h"

/**
 * tokenize - Split a string into arguments
 *
 * @command: The string to tokenize
 *
 * Return: An array of pointers to the arguments
 */

char **tokenize(char *command)
{/* Declaration of Variables */
	char **args = NULL;
	char *token = NULL;
	const char *dlm = " '\t''\n''\0'";
	int i = 0;

/* Code Statements*/
	args = malloc(sizeof(char *) * MAX_ARGS);
	if (!args)
	{
		perror("shell");
	}
	if (!command)
	{
		return (NULL); }
	token = strtok(command, dlm); /* Get first argument */
	while (token)
	{
		args[i] = _strdup(token); /* Save the argument */
		token = strtok(NULL, dlm); /* Get next argument */
		i++;
		if (i >= MAX_ARGS) /* Check for too many arguments */
		{
			break; }
	}
	args[i] = token; /* Mark the end of the argument list */
	return (args);
}
