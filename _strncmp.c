#include "shell.h"

/**
 * _strncmp - function in C that compares the first n characters of
 * two strings s1 and s2.
 *
 * @s1: character pointer to first string.
 * @s2: character pointer to second string.
 * @n: integer value of number of characters to be compared
 *
 * Return: Integer Value. 0 (Always Success!) or 1 (Failure).
 */

int _strncmp(char *s1, char *s2, int n)
{/* Declaration of Variables */
	int i = 0;

/* Code Statements */
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else if (s1[i] == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
