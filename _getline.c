#include "shell.h"

/**
 * getline - Split a string into arguments
 *
 * @lineptr: character pointer where the buffer is to be stored.
 * @n: integer value representing buffer size.
 * @stream:
 *
 * Return: Integer Value of bytes read.
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{/* Declaration of Variables */
int fd = fileno(stream);
char buf[1];
size_t bytes_read = 0, len = 0;
ssize_t bytes_read_total = 0;
char *line = NULL, *new_line;

/* Code Statements*/
	if (!lineptr || !n)
	{
		errno = EINVAL;
		return (-1); }
	while (read(fd, buf, 1) == 1)
	{
		if (bytes_read >= len)
		{
			len += 128;
			new_line = realloc(line, len);
			if (!new_line)
			{
				free(line);
				return (-1); }
			line = new_line;
		}
		line[bytes_read++] = buf[0];
		bytes_read_total++;
		if (buf[0] == '\n')
		{
			break;
		}
	}
	if (bytes_read_total == 0)
	{
		free(line);
		return (-1); }
	line[bytes_read] = '\0';
	*lineptr = line;
	*n = len;
	return (bytes_read_total);
}

