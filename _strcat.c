#include "shell.h"

/**
 * _strcat - swaps the values of two integers
 *
 * @dest: first string
 * @src: second string
 *
 * Return: Concatenated string
 */

char *_strcat(char *dest, char *src)
{
/*Declaration of variables*/
	int dest_len = 0, i;

/*Code Logic*/
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
