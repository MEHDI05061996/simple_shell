#include "shell.h"

/**
 * _strcspn - function that finds the length of the initial segment of
 * a string that does not contain any of a specified set of characters.
 *
 * @s: character pointer to string to be processed.
 * @reject: character pointer to characters to e rejected.
 *
 * Return: Integer value of number of characters matching criteria.
 */

int _strcspn(const char *s, const char *reject)
{
	const char *p, *r;
	int count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}
