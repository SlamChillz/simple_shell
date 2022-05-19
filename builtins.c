#include "main.h"

/**
 * _xit - exit the program with a status code
 *
 * @in: input from terminal
 * @argv: array of program name
 * @n: number of shell loops
 * @tokens: array of tokens
 *
 * Return: void
 */
void _xit(char *in, char **argv, char **tokens, int n)
{
	int i = 0, status;

	if (tokens[1] == NULL)
	{
		free(in), freearray(tokens);
		exit(EXIT_SUCCESS);
	}
	while (tokens[1][i])
	{
		if (_isalpha(tokens[1][i++]) != 0)
		{
			exiterror(argv, tokens, n);
			free(in), freearray(tokens);
			return;
		}
	}
	if (_atoi(tokens[1]) >= 0)
	{
		status = _atoi(tokens[1]);
		free(in), freearray(tokens);
		exit(status);
	}
	else if (_atoi(tokens[1]) < 0)
	{
		exiterror(argv, tokens, n);
		/* free(in), freearray(tokens); */
		return;
	}
}

/**
 * env - display environmental variables
 * @tokens: pointer to an array of strings
 * @stat: status number
 * Return: status code
 */
int env(char **tokens, int *stat)
{
	int i;
	(void)(stat);

	if (tokens[1])
	{
		print("env: '"), print(tokens[1]);
		print("’: No such file or directory\n");
		return (127);
	}

	for (i = 0; environ[i]; i++)
	{
		print(environ[i]);
		print("\n");
	}
	return (0);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @tokens: array of strings
 * @stat: status number
 * Return: integer
 */
int _setenv(char **tokens, int *stat)
{
	int i, k, n;
	(void)(stat);

	if (!tokens[1] || !tokens[2])
	{
		print("Error: Usage-> setenv VARIABLE VALUE\n");
		return (127);
	}
	for (i = 0; environ[i]; i++)
	{
		k = 0;
		if (tokens[1][k] == environ[i][k])
		{
			for (; tokens[1][k]; k++)
			{
				if (tokens[1][k] != environ[i][k])
					break;
			}
			if (tokens[1][k] == '\0')
			{
				n = 0;
				for (; tokens[2][n]; n++)
				{
					environ[i][k + 1 + n] = tokens[2][n];
				}
				environ[i][k + 1 + n] = '\0';
				return (0);
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = join(tokens[1], "=", tokens[2]);
		environ[i + 1] = NULL;
	}
	return (0);
}

/**
 * _unsetenv - unset environmental variables
 * @tokens: pointer to an array of strings
 * @stat: status number
 * Return: integer
 */
int _unsetenv(char **tokens, int *stat)
{
	int i, k;
	(void)(stat);

	if (!tokens[1] || tokens[2])
	{
		print("Error: Usage-> unsetenv VARIABLE\n");
		return (0);
	}
	for (i = 0; environ[i]; i++)
	{
		k = 0;
		if (tokens[1][k] == environ[i][k])
		{
			for (; tokens[1][k]; k++)
			{
				if (tokens[1][k] != environ[i][k])
					break;
			}
			if (tokens[1][k] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				for (; environ[i]; i++)
					environ[i] = environ[i + 1];
				return (0);
			}
		}
	}
	print("Error: Variable "), print(tokens[1]), print(" not found\n");
	return (127);
}

/**
 * _getenv - get environment variable
 * @var: pointer to a string
 *
 * Return: pointer to the variable value
 */
char *_getenv(char *var)
{
	int i, k;
	char *value;

	if (var == NULL)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		k = 0;
		if (var[k] == environ[i][k])
		{
			for (; var[k]; k++)
			{
				if (var[k] != environ[i][k])
					break;
			}
			if (var[k] == '\0')
			{
				value = (environ[i] + k + 1);
				return (value);
			}
		}
	}
	return (NULL);
}
