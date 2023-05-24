#include "shell.h"

/**
 * _strncpy - function that copies a string
 *
 * @dest: destination string
 * @src: source string
 * @n: number
 *
 * Return: Destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
/*Declaration of variables*/
	int i;

/*Code Logic*/
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
