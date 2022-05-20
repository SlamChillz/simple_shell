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
 * int_mode - Interactive mode
 *
 * @argv: argument variables
 */
void int_mode(char **argv)
{
	char *t_input = NULL, *input = NULL, **tokens;
	int status, loop = 0, read;
	size_t bufflen = 0;

	while (1)
	{
		loop++;
		if (isatty(STDIN_FILENO))
			prompt();
		read = _getline(&t_input, &bufflen, stdin);
		if (read == EOF)
		{
			free(t_input);
			exit(0);
		}
		if (!t_input)
		{
			free(t_input);
			break;
		}
		input = rem_(t_input);
		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			continue;
		}
		tokens = tokenise(input);

		if (_strcmp(tokens[0], "exit") == 0)
			_xit(input, argv, tokens, loop);
		else
			status = execute(tokens, loop);
		freearray(tokens);
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
	char *input = NULL, *t_input = NULL, **args;

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
			t_input = line;
			input = rem_(t_input);
			if (input[0] == '\0' || _strcmp(input, "\n") == 0)
			{
				free(t_input);
				continue;
			}
			args = tokenise(input);
			status = execute(args, loop);
			freearray(args);
		}
	}
	fclose(fptr);
	return (status);
}

