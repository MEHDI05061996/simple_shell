/**
 * c_omit - custom ignores spaces and newlines
 *
 * @str: envrionmental variables
 *
 * Return: new string
 */

char *c_omit(char *str)
{
	while (*str == ' ' || *str == '\n')
	{
		str++; }
	return (str);
}
