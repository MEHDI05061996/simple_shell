#include "shell.h"

/**
 * find_executable - Function that locates executables in cwd.
 *
 * @name: character pointer to
 *
 * Return: character pointer to full path or NULL.
 */

char *find_executable(char *name)
{/* Declaration of Variables */
	char *cwd = getcwd(NULL, 0), *full_path;
	struct stat st;
	int fd;

/* Code Statements */
	if (!cwd)
	{
		return (NULL);
	}
	fd = open(cwd, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
	{
		perror("find_executable");
		free(cwd);
		return (NULL);
	}
	full_path = malloc(_strlen(cwd) + _strlen(name) + 2);
	if (!full_path)
	{
		perror("find_executable");
		close(fd);
		free(cwd);
		return (NULL);
	}
	_strcpy(full_path, cwd);
	_strcat(full_path, "/");
	_strcat(full_path, name);
	if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode))
	{
		close(fd);
		free(cwd);
		return (full_path);
	}
	free(full_path);
	close(fd);
	free(cwd);
	return (NULL);
}
