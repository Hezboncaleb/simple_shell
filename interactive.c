#include "main.h"

/**
 * handle_interactive - handles interactive shell scripts
 * @argc: number of arguments
 * @argv: command line arguments
 * @env: double pointer to environmental variables
 * Return: void
*/

void handle_interactive(int argc, char *argv[], char **env)
{
	char *txt = "$ ", *lineptr = NULL, *curr = argv[0];
	char new[MAX_INPUT_LENGTH] = "/bin/";
	size_t n = MAX_INPUT_LENGTH;
	int bytes_read;

	while (1)
	{
		bytes_read = prompt(txt, &lineptr, &n);
		if (bytes_read == -1)
		{
			perror(curr);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		argc = 0;
		_strtoarr(argv, lineptr, argc);
		if (handle_exceptional_inputs(curr, argv, lineptr) == 1)
			continue;
		argv[0] = _charfinder(argv[0], '/') != 1 &&
			_strlen(argv[0]) > 0 ? _strcat(new, argv[0]) : argv[0];
		if (access(argv[0], X_OK) == 0)
			_fork(curr, argv, env);
		else
		{
			_strcpy(argv[0], "/bin/");
			perror(curr);
		}
	}
	free(lineptr);
}
