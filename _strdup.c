#include "shell.h"

/**
 * _strdup - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a
 * parameter
 *
 * @str: pointer of type char
 *
 * Return: Duplicated string
 */


char *_strdup(char *str)
{
/*Declaration of variables*/
	char *dup_str;

/*Code Statements*/
	if (str == NULL)
	{/* Check if str is NULL */
		return (NULL);
	}
	/* Allocate memory for the new string */
	dup_str = malloc(_strlen(str) + 1);
	if (dup_str == NULL)
	{
		return (NULL);
	}
	/* Copy the contents of str to the new string */
	_strcpy(dup_str, str);

	return (dup_str);
}
