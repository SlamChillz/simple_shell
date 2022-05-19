#include "main.h"

/**
 * _isalpha - Alphabet check
 * @c: parameter must be an integer value
 *
 * Return: 1 if c is a letter, else 0
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert string to integer
 * @s: string to be coverted
 * Description: a function that convert a string to an integer.
 *
 * Return: integer else 0 if no number in the string
 */
int _atoi(char *s)
{
	int i, j, n, x;

	if (s == NULL)
		return (0);

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _intlen - calculate length of an interger
 * @n: integer
 *
 * Return: integer, length of given integer
 */
int _intlen(int n)
{
	int len = 0;

	while (n)
		len++, n /= 10;

	return (len);
}

/**
 * _itoa - convert an integer to a string
 * @n: unsigned integer
 *
 * Return: string pointer
 */
char *_itoa(unsigned int n)
{
	int len = _intlen(n), i = 0;
	char *s = malloc(len + 1);

	if (s == NULL)
		return (NULL);

	for ( ; n; i++)
		s[i] = (n % 10) + '0', n /= 10;
	s[i] = '\0';
	_reverse(s);
	return (s);
}
