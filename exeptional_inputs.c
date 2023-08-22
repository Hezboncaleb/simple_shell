#include "main.h"

/**
 * handle_exceptional_inputs - handles inputs
 * @curr: current executable
 * @envp: double pointer to the environment variables
 * @arr: tokenized array
 * @lineptr: original input pointer
 * Return: 1 if it is executed, otherwise 0
 */

int handle_exceptional_inputs(char *curr, char **envp,
		char *arr[], char *lineptr)
{
	if (_strcmp(arr[0], "env") == 0)
	{
		handle_env(envp);
		return (1);
	}
	else if (_strcmp(arr[0], "exit") == 0)
	{
		handle_exit(arr, lineptr);
		return (1);
	}
	else if (_strcmp(arr[0], "cd") == 0)
	{
		handle_cd(curr, arr);
		return (1);
	}
	return (0);
}
/**
 * handle_cd - handles change of directory
 * @curr: current executable
 * @arr: array containing path
 * Return: void
 */

void handle_cd(char *curr, char *arr[])
{
	int status;

	if (_strlen(arr[1]) == 0 || arr[1] == NULL)
	{
		char *dir;

		dir = getenv("HOME");
		status = chdir(dir);
		if (status == -1)
		{
			perror(curr);
		}
	}
	else if (_strcmp(arr[1], "-") == 0)
	{
		write(1, getcwd(arr[1], MAX_INPUT_LENGTH), MAX_INPUT_LENGTH);
		write(1, "\n", 1);
	}
	else if (arr[1])
	{
		status = chdir(arr[1]);
		if (status == -1)
		{
			perror(curr);
		}
	}
}
