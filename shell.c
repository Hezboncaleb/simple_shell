#include "main.h"

/**
 * main - Handles simple shell
 * @argc: number of arguments
 * @argv: command line arguments
 * @env: double pointer to environmental variables
 * Return: 0(success)
 */

int main(int argc, char *argv[], char **env)
{
	char *txt = "$ ", *lineptr = NULL, *curr = argv[0];
	size_t n = MAX_INPUT_LENGTH;
	int bytes_read;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			bytes_read = prompt(txt, &lineptr, &n);
			if (bytes_read == -1)
			{
				perror(curr), free(lineptr);
				exit(EXIT_FAILURE);
			}
			argc = 0, _strtoarr(argv, lineptr, argc, " ");
			if (handle_exceptional_inputs(curr, argv, lineptr) == 1)
				continue;
			handle_query(argv, env, curr);
		}
	}
	else
	{
		bytes_read = _read(&lineptr, &n);
		if (bytes_read == -1)
		{
			perror(curr), free(lineptr);
			exit(EXIT_FAILURE);
		}
		argc = 0, _strtoarr(argv, lineptr, argc, " ");
		if (handle_exceptional_inputs(curr, argv, lineptr) == 1)
		{
			free(lineptr), exit(EXIT_SUCCESS);
		}
		handle_query(argv, env, curr), free(lineptr);
	}
	return (0);
}
