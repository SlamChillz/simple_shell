#include "main.h"

/**
 * printerror - print error message and shell loop count
 * @in: pointer to an array of strings, user input
 * @name: pointer to program name
 * @loop: number of shell loops
 *
 * Return: void
 */
void printerror(char *name, char *in, int loop)
{
	char *e = _itoa(loop);

	print(name);
	print(": ");
	print(e), free(e);
	print(": ");
	print(in);
	print(": not found\n");
}

/**
 * exiterror - print error message and shell loop count
 * @argv: pointer to an array of strings, user input
 * @tokens: pointer to program name
 * @loop: number of shell loops
 *
 * Return: void
 */
void exiterror(char **argv, char **tokens, int loop)
{
	char *e = _itoa(loop);

	print(argv[0]), print(": "), print(e), print(": ");
	print(tokens[0]), print(": Illegal number: "), print(tokens[1]);
	print("\n"), free(e);
}
