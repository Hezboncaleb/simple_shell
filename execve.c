#include "main.h"

/**
 * _execve - executes programs
 * @curr: name of executing program
 * @arr: array
 * @env: environmental variables
 * Return: void
 */

void _execve(char *curr, char *arr[], char **env)
{
	int exec_res;

	exec_res = execve(arr[0], arr, env);
	if (exec_res == -1)
	{
		perror(curr);
	}
}
