#include "monty.h"

/**
 * _isdigit - checks for a digit 0 through 9
 * @c: is the char to be checked
 * Return: 1 if c is a digit, otherwise 0
 */

int _isdigit(int c)
{

	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * is_number - function that checks if arg is an int
 * @str: the input
 * Return: 0
 */
int is_number(char *str)
{
	while (*str)
	{
		if (!_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * is_negative_number - function that checks if arg is -ve int
 * @str: the input
 * Return: 0
 */

int is_negative_number(char *str)
{
	if (str[0] == '-' && is_number(str + 1))
	{
		return (1);
	}
	return (0);
}

