#include "main.h"

/**
 * _fork - executes programs
 * @curr: name of executing program
 * @arr: array
 * @env: environmental variables
 * Return: void
 */

void _fork(char *curr, char *arr[], char **env)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(curr);
		exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		int status;

		waitpid(child_pid, &status, 0);
		_strcpy(arr[0], "/bin/");
	}
	else
	{
		_execve(curr, arr, env);
		_strcpy(arr[0], "/bin/");
	}
}
