#include "shell.h"

/**
 * tokenize_path - Function to tokenize PATH variable.
 *
 * @argv: character pointer to character strings passed to
 * main program
 *
 * Return: character pointer to buffer holding path tokens
 */

char **tokenize_path(char **argv)
{/* Declaration of Variables */
	char *path = NULL, *path_copy = NULL, **tokens = NULL, *token = NULL;
	int i, count = 0, index = 0;

/* Code Statements */
	path = _getenv("PATH");
	if (path == NULL)
	{
		handle_errors(&argv[0]);
		return (NULL); }
	path_copy = strdup(path);
	if (path_copy == NULL)
	{/* Making a copy of path because strtok modifies the original string */
		handle_errors(&argv[0]);
		return (NULL); }
	for (i = 0; path_copy[i] != '\0'; i++)
	{/* Count how many directories are in the PATH */
		if (path_copy[i] == ':')
		{
			count++; }
	}
	tokens = malloc((count + 2) * sizeof(char *));
	if (tokens == NULL)
	{/* Allocate memory for token array */
		handle_errors(&argv[0]);
		free(path_copy);
		return (NULL); }
	token = strtok(path_copy, ":");
	while (token != NULL)
	{/* Tokenize PATH */
		tokens[index] = strdup(token);
		token = strtok(NULL, ":");
		index++; }
	tokens[index] = NULL;
	free(path_copy);/* Free the copied path */
	return (tokens);
}
