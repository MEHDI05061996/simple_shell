#include "shell.h"

/**
 * _strcpy - function in the C programming language that
 * is used to copy a string from one memory location to another.
 *
 * @dest: character pointer to destination string.
 * @src: character pointer to source string.
 *
 * Return:  Character pointer to destination string.
 */

char *_strcpy(char *dest, const char *src)
{/* Declaration of Variables */
	int i = 0;

/* Code Statements */
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
