#include "main.h"

/**
 * _chdir - change current work directory
 * @tokens: array of strings
 * @stat: status
 *
 * Return: integer, execution status
 */
int _chdir(char **tokens, int *stat)
{
	char cwd[PATH_MAX];
	char *arr[4];
	int status;
	(void)(stat);

	if (tokens[1] == NULL)
	{
		status = chdir(_getenv("HOME"));
	}
	else if (_strcmp(tokens[1], "-") == 0)
	{
		print(_getenv("OLDPWD")), print("\n");
		status = chdir(_getenv("OLDPWD"));
	}
	else
	{
		status = chdir(tokens[1]);
	}
	if (status == -1)
	{
		print("./hsh: "), _putchar(6 + '0');
		print(": cd: can't cd to "), print(tokens[1]), print("\n");
		return (127);
	}
	getcwd(cwd, sizeof(cwd));
	if (cwd == NULL)
	{
		perror("hsh");
		return (-1);
	}
	arr[0] = "setenv", arr[1] = "OLDPWD", arr[2] = _getenv("PWD");
	arr[3] = NULL;
	_setenv(arr, stat);
	arr[0] = "setenv", arr[1] = "PWD", arr[2] = cwd, arr[3] = NULL;
	_setenv(arr, stat);
	return (0);
}

/**
 * _echo - to handle special echo cases
 * @token: array of parsed strings
 * @status: status
 *
 * Return: integer value, exit status
 */
int _echo(char **token, int *status)
{
	char *path, *e;
	pid_t pid = getppid();

	if (token[1] == NULL)
		return (1);
	if (_strncmp(token[1], "$?", 2) == 0)
	{
		if (*status == 0)
		{
			_putchar(*status + '0');
		}
		else
		{
			e = _itoa(*status);
			_printf(e), free(e);
		}
		_printf("\n");
		return (0);
	}
	else if (_strncmp(token[1], "$$", 2) == 0)
	{
		e = _itoa(pid);
		_printf(e), _printf("\n"), free(e);
		return (0);
	}
	else if (token[1][0] == '$')
	{
		e = token[1];
		path = _getenv(++e);
		if (path == NULL)
			return (1);
		_printf(path), _printf("\n");
		return (0);
	}
	return (1);
}

/**
 * echocheck - check if path is echo
 * @str: path value
 *
 * Return: integer, 1 if true else 0
 */
int echocheck(char *str)
{
	int len;

	len = _strlen(str);
	str = str + len - 4;

	return (_strcmp(str, "echo"));
}

