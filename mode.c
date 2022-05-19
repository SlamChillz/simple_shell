#include "main.h"

/**
 * rem_spe - remove special characters
 *
 * @str: input string
 * Return: Modified string
 */
char *rem_spe(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * rem_ - remove spaces
 *
 * @str: input string
 * Return: Modified string
 */
char *rem_(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * nonint - Non-interactive mode
 *
 * @argv: argument variables
 */
void nonint(char **argv)
{
	char *input, *t_input, **tokens;
	int status, loop = 1;

	t_input = readline();
	if (!t_input)
		exit(0);
	input = rem_spe(t_input);
	if (input[0] == '\0')
	{
		free(t_input);
		exit(0);
	}
	tokens = tokenise(input);

	if (_strcmp(tokens[0], "exit") == 0)
		_xit(input, argv, tokens, loop);
	else
		status = execute(tokens, loop);
	free(t_input), freearray(tokens);
	exit(status);
}

/**
 * int_mode - Interactive mode
 *
 * @argv: argument variables
 */
void int_mode(char **argv)
{
	char *input, *t_input, **tokens;
	int status, loop = 0;

	while (1)
	{
		loop++;
		if (isatty(STDIN_FILENO))
			prompt();
		else
			nonint(argv);
		t_input = readline();
		if (!t_input)
			break;
		input = rem_(t_input);
		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			free(t_input);
			continue;
		}
		tokens = tokenise(input);

		if (_strcmp(tokens[0], "exit") == 0)
			_xit(input, argv, tokens, loop);
		else
			status = execute(tokens, loop);
		free(t_input), freearray(tokens);
		continue;
	}
	exit(status);
}

/**
 * batch_mode - batch run a script
 *
 * @filename: name of file
 * Return: status
 */
int batch_mode(char *filename)
{
	FILE *fptr;
	int status, loop = 0;
	char line[1024];
	char **args;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		perror("Error:");
		return (1);
	}
	else
	{
		while (fgets(line, sizeof(line), fptr) != NULL)
		{
			loop++;
			args = tokenise(line);
			status = execute(args, loop);
			freearray(args);
		}
	}
	fclose(fptr);
	return (status);
}
