#include "shell.h"

/**
 * _strrchr - function returns a pointer to the first occurrence
 * of the character c in the string s.
 *
 * @s: Character pointer to buffer containing the string.
 * @c: Character whose first occurence is to be sought.
 *
 * Return: Character pointer to buffer containing matched character.
 */

char *_strrchr(const char *s, int c)
{
	char *last = NULL;

	do {
		if (*s == (char)c)
		last = (char *)s;
	} while (*s++);
	return (last);
}
