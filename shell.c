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
	char *txt = "#cisfun$ ", *lineptr = NULL;
	char new[MAX_INPUT_LENGTH] = "/bin/";
	char *curr = argv[0];
	size_t n = MAX_INPUT_LENGTH;
	int flag = 1, bytes_read;

	while (flag)
	{
		fflush(stdout);
		bytes_read = prompt(txt, &lineptr, &n);
		if (bytes_read == -1)
		{
			perror(curr);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		argc = 0;
		_strtoarr(argv, lineptr, argc);
		if (handle_exceptional_inputs(curr, env, argv, lineptr) == 1)
		{
			continue;
		}
		argv[0] = _charfinder(argv[0], '/') != 1 &&
			_strlen(argv[0]) > 0 ? _strcat(new, argv[0]) : argv[0];
		if (access(argv[0], X_OK) == 0)
		{
			_fork(curr, argv, env);
		}
		else
		{
			_strcpy(new, "/bin/");
			perror(curr);
		}
	}
	free(lineptr);
	return (0);
}
