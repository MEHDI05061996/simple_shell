#include "shell.h"

/**
 * readline - Function that reads line from standard input.
 *
 * Return: Character pointer to line
 */

char *readline()
{
	char *line = malloc(BUFSIZE), c, *new_line;
	int pos = 0, n;

	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		n = read(STDIN_FILENO, &c, 1);
		if (n == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (n == 0 || c == '\n')
		{
			line[pos] = '\0';
			return (line);
		}
		else
		{
			line[pos++] = c;
			if (pos == BUFSIZE)
			{
				new_line = malloc(BUFSIZE * 2);
				if (!new_line)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}
				_memcpy(new_line, line, BUFSIZE);
				free(line);
				line = new_line;
			}
		}
	}
}
