#include "main.h"

/**
 * _putchar - print a character to the standard input
 * @c: character
 *
 * Return: void
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * prompt - display shell interactive prompt
 *
 * Return: void
 */
void prompt(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signal_handr);
	print("($) ");
}

/**
 * signal_handr - handle signals
 *
 * @signum: Signal value
 */
void signal_handr(int signum)
{
	(void)(signum);

	print("\n($) ");
	fflush(stdout);
}

/**
 * print - print a string to standard output
 * @s: pointer to a string
 *
 * Return: void
 */
void print(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}
