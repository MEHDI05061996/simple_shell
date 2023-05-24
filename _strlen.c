#include "shell.h"

/**
 * _strlen - This function return a length for some string
 *
 * @s: character pointer ro string in question.
 *
 * Return: integer value of length of string.
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s++)
	{
		len++;
	}
	return (len);
}
