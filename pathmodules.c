#include "main.h"

/**
 * path - check if the command exit in PATH
 * @token: array to to a string of characters
 * @loop: loop number
 * Return: path, if found or NULL
 */
int path(char **token, int loop)
{
	int i = 0;
	char *path, **paths, *prev = token[0];
	struct stat st;

	if (prev[0] != '/')
	{
		paths = tokenise(_getenv("PATH"));
		while (paths[i])
		{
			path = join(paths[i], "/", prev);
			if (stat(path, &st) == 0)
			{
				token[0] = path;
				free(prev), freearray(paths);
				return (1);
			}
			free(path);
			i++;
		}
		freearray(paths);
	}
	else
	{
		if (stat(prev, &st) == 0)
			return (1);
	}
	printerror("./hsh", prev, loop);
	return (0);
}

/**
 * cut - create a array of tokens
 * @token: pointer to an array of strings
 * @n: number of strings to segment
 *
 * Return: array of strings
 */
char **cut(char **token, int n)
{
	int i = 0;
	char **t;

	t = malloc(sizeof(char *) * (n + 1));
	if (t == NULL)
		return (NULL);
	while (i < n)
	{
		t[i] = _strdup(token[i]);
		i++;
	}
	t[i] = NULL;
	return (t);
}

/**
 * checkoperand - check if an operand exists in token
 * @str: array of characters
 *
 * Return: integer, 1 if present, 0 if not
 */
int checkoperand(char *str)
{
	if (_strcmp(str, "||") == 0)
		return (1);
	else if (_strcmp(str, "&&") == 0)
		return (1);
	else if (_strcmp(str, ";") == 0)
		return (1);
	else
		return (0);
}

/**
 * run - run command in snippets
 * @token: array of tokens
 * @prev:status number
 * @op: operator
 * @loop: loop number
 * Return: void
 */
void run(char **token, int *prev, char *op, int loop)
{
	if (op == NULL || _strcmp(op, ";") == 0)
	{
		*prev = _execbuiltins(token, prev);
		/* printf("%d\n", prev); */
		if (*prev == 1)
			*prev = _execpath(token, loop, prev);
	}
	else if ((*prev == 0) && (_strcmp(op, "&&") == 0))
	{
		*prev = _execbuiltins(token, prev);
		if (*prev == 1)
			*prev = _execpath(token, loop, prev);
	}
	else if ((*prev != 0) && (_strcmp(op, "||") == 0))
	{
		*prev = _execbuiltins(token, prev);
		if (*prev == 1)
			*prev = _execpath(token, loop, prev);
	}
}

/**
 * execute - as the name implies, execute a command
 * @tokens: array of strings
 * @loop: loop number
 * Return: exit status
 */
int execute(char **tokens, int loop)
{
	int i, n = 0, prev;
	char *op, **token;

	prev = -1, op = NULL;
	for (i = 0; tokens[i]; i++)
	{
		if (checkoperand(tokens[i]) && checkoperand(tokens[i + 1]))
		{
			print("./hsh: "), _putchar(loop + '0');
			print(": Syntax error: \""), print(tokens[i + 1]);
			print("\" unexpected\n");
			return (1);
		}
	}
	for (i = 0; tokens[i]; i++)
	{
		if (checkoperand(tokens[i]))
		{
			token = tokens + i - n;
			token = cut(token, n);
			run(token, &prev, op, loop);
			freearray(token);
			op = tokens[i];
			n = 0;
			continue;
		}
		n++;
	}
	token = tokens + i - n;
	token = cut(token, n);
	run(token, &prev, op, loop);
	freearray(token);
	return (prev);
}
