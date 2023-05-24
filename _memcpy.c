#include "shell.h"

/**
 * _memcpy - function that copies memory area
 *
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of byte to be filled
 *
 * Return: pointer to the memory area dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
/* Declaration of Variables */
	unsigned int i;

/* Code Statements */
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
