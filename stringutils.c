#include "main.h"

/**
 * _strlen - calculate string length
 * @s: string whose length is to be determined
 * Description: a function that returns the length of a string.
 *
 * Return: integer(sum of string characters)
 */
int _strlen(char *s)
{
	int i = 0, sum = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		sum = sum + 1;
		i++;
	}
	return (sum);
}

/**
 * _strcpy - copy str1 into str2
 * @dest: string to copy into
 * @src: string to copy from
 * Description:  a function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (&dest[0]);
}

/**
 * _reverse - reverse a string
 * @s: string to be reverse
 * Description: a function that reverses a string.
 *
 * Return: None
 */
void _reverse(char *s)
{
	int i = 0, x = 0, y;

	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (i > x)
	{
		y = s[i];
		s[i--] = s[x];
		s[x++] = y;
	}
}

/**
 * join - concatenate 3 strings together
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * @s3: pointer to string 3
 *
 * Return: pointer to result string
 */
char *join(char *s1, char *s2, char *s3)
{
	char *str;
	int i, k, len1, len2, len3;

	len1 = _strlen(s1), len2 = _strlen(s2), len3 = _strlen(s3);

	str = malloc(len1 + len2 + len3 + 1);
	if (!str)
		return (NULL);

	for (i = 0; s1[i]; i++)
		str[i] = s1[i];
	k = i;

	for (i = 0; s2[i]; i++)
		str[k + i] = s2[i];
	k += i;

	for (i = 0; s3[i]; i++)
		str[k + i] = s3[i];

	str[k + i] = '\0';

	return (str);
}
