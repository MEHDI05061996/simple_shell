#include "shell.h"

/**
 * check_path - Check if a command exists in the directories specified by PATH
 *
 * @command: The name of the command to check
 * @path: An array of directories to search in
 * @full_path: A pointer to a character buffer where the full path of the
 * command will be stored
 *
 * Return: 1 if the command exists in one of the directories, 0 otherwise
 */

int check_path(const char *command, char **path, char *full_path)
{
	int i, j, k;
	struct stat st;

	for (i = 0; path[i] != NULL; i++)
	{/* Copy the path to the command to the full_path buffer */
		for (j = 0; path[i][j] != '\0'; j++)
		{
			full_path[j] = path[i][j];
		}
		full_path[j] = '/';
		j++;
		for (k = 0; command[k] != '\0'; k++, j++)
		{/* Copy the command to the full_path buffer */
			full_path[j] = command[k];
		}
		full_path[j] = '\0';
		if (stat(full_path, &st) == 0 && st.st_mode & S_IXUSR)
		{/* Check if the file exists and is executable */
			return (1);
		}
	}
	return (0);
}
