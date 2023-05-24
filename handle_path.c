#include "shell.h"

/**
 * handle_path - Function that compares command line to
 * path values and executes if a match is found.
 *
 * @args: character pointer to buffers holding parsed command line arguments.
 * @argv: character pointer to buffers holding program arguments.
 *
 * Return: Character pointer to buffer holding string to be passed to
 * execve.
 */


char *handle_path(char **args, char **argv)
{/* Declaration of Variables */
	char **path = NULL, *dir_path = NULL, *full_path = NULL;
	int i;

/* Code Statements */
	if (access(args[0], X_OK) == -1)
	{/* Check if command can be accessed without searching PATH */
		path = tokenize_path(&argv[0]);
		for (i = 0; path[i] != NULL; i++)
		{/* check if command exists in PATH directories */
			dir_path = path[i];
			full_path = malloc(_strlen(dir_path) + _strlen(args[0]) + 3);
			_strcpy(full_path, dir_path);
			_strcat(full_path, "/");
			_strcat(full_path, args[0]);
			if (access(full_path, X_OK) == -1)
			{
				continue; }
			else
			{
				free(path);
				return (full_path); }
		}
		free(path);
	}
	else
	{
		return (args[0]); }
	return (NULL);
}

