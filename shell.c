#include "main.h"

/**
 * main - program entry
 * @argc: number of commandline arguments
 * @argv: array of commandline parameters
 *
 * Return: integer
 */
int main(int argc, char **argv)
{
	int status;
	(void)(argc), (void)(argv);

	if (argc == 2)
	{
		status = batch_mode(argv[1]);
		exit(status);
	}
	else
		int_mode(argv);
	return (0);
}
