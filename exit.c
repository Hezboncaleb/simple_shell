#include "main.h"

/**
 * handle_exit - function that handles theexit command
 * @arr: array containing status
 * @lineptr: address to be freed before exit
 * @curr: current executable
 * Return: nothing
 */

void handle_exit(char *arr[], char *lineptr, char *curr)
{
	int status, i;

	if (arr[1] != NULL)
	{
		for (i = 0; arr[1][i] != '\0'; i++)
		{
			if ((arr[1][i] < 48) || (arr[1][i] > 57))
			{
				dprintf(2, "%s 1: exit: Illegal number: %s\n", curr, arr[1]);
				exit(2);
			}
		}
		status = _strtoint(arr[1]);
		free(lineptr);
		_exit(status);
	}
	else
	{
		free(lineptr);
		_exit(EXIT_SUCCESS);
	}
}
