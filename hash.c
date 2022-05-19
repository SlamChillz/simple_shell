#include "main.h"

/**
 * hashtag - remove characters from # to the end
 * @buff: pointer to an array of string
 *
 * Return: void
 */
void hashtag(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
