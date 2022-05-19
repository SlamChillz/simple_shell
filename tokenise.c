#include "main.h"

/**
 * _strcount - determine the length of string by delmiters
 * @str: pointer to string
 *
 * Return: integer, length
 */
int _strcount(char *str)
{
	int c = 0, i, k, len = 0, delim;

	for (i = 0; str[i] != '\0'; i++)
	{
		delim = 0;
		for (k = 0; DELIMS[k] != '\0'; k++)
		{
			if (str[i] == DELIMS[k])
			{
				delim = 1;
				if (c > 0)
					len++, c = 0;
				break;
			}
		}
		if (!delim)
			c++;
		if ((c > 0) && str[i + 1] == '\0')
			len++;
	}
	return (len);
}

/**
 * tokenise - parse inputs into tokens
 * @str: pointer to a string
 *
 * Return: array of pointers
 */
char **tokenise(char *str)
{
	char **tokens, *p;
	int c = 0, i, k, n = 0, len = 0, delim;

	len = _strcount(str);
	tokens = malloc((len + 1) * sizeof(*tokens));
	if (tokens == NULL || str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		delim = 0;
		for (k = 0; DELIMS[k] != '\0'; k++)
		{
			if (str[i] == DELIMS[k])
			{
				delim = 1;
				if (c > 0)
				{
					p = str + i - c, p = copy(p, c);
					if (p == NULL)
						return (NULL);
					tokens[n++] = p, c = 0;
				}
				break;
			}
		}
		if (delim == 0)
			c++;
		if ((c > 0) && str[i + 1] == '\0')
		{
			p = str + i + 1 - c, p = copy(p, c);
			if (p == NULL)
				return (NULL);
			tokens[n++] = p;
		}
	}
	tokens[n] = NULL;
	return (tokens);
}

/**
 * copy - copy n characters from a string
 * @str: pointer to a string
 * @n: integer, number of characters to copy
 *
 * Return: pointer to the copied string
 */
char *copy(char *str, int n)
{
	int i = 0;
	char *p;

	p = malloc((n + 1) * sizeof(*p));
	if (p == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
