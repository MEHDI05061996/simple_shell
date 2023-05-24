#include "shell.h"

/**
 * free_envp - Function that frees alocated memory.
 *
 * @envp: Character pointer to buffers holding environmental
 * variable values.
 */

void free_envp(char **envp)
{
	int i;

/* Loop through each element of envp and free it */
	for (i = 0; envp[i] != NULL; i++)
	{
		free(envp[i]); }
/* Finally, free the envp itself */
	free(envp);
}

