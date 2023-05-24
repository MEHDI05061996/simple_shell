#include "shell.h"

/**
 * _getenv - Function that gets an environment variable.
 *
 * @name: character pointer to environment variable name
 *
 * Return: Character pointer to environment variables.
 */

char *_getenv(char *name)
{/* Declaration of Variables */
	char *value = NULL;
	char **env;
	int k;
	size_t name_len = _strlen(name);

/* Code Statements */
	env = environ;
	for (k = 0; env[k] != NULL; k++)
	{
		if (_strncmp(name, env[k], name_len) == 0 && env[k][name_len] == '=')
		{
			value = env[k] + name_len + 1;
			break;
		}
	}
	return (value);
}
