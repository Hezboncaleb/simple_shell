#include "main.h"

/**
 * handle_exit - function that handles theexit command
 * @arr: array containing status
 * @lineptr: address to be freed before exit
 * Return: nothing
 */

void handle_exit(char *arr[], char *lineptr)
{
	int status;

	if (arr[1])
	{
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
