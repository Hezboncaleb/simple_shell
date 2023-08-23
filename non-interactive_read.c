#include "main.h"

/**
 * _read - for non-interactive scripts
 * @buffer: input storage
 * @n: buffer size
 * Return: bytes read
 */

size_t _read(char **buffer, size_t *n)
{
	int bytes_read = 0;

	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * (*n));
		if (buffer == NULL)
		{
			perror("Error allocating memory");
			return (-1);
		}
	}
	bytes_read = read(0, *buffer, *n);
	if (bytes_read > 0)
		*(*buffer + (bytes_read - 1)) = '\0';
	return (bytes_read);
}

/**
 * handle_noninteractive - handles non-interactive shell scripts
 * @argc: number of arguments
 * @argv: command line arguments
 * @env: double pointer to environmental variables
 * Return: void
*/
void handle_noninteractive(int argc, char *argv[], char **env)
{
	char *lineptr = NULL, new[MAX_INPUT_LENGTH] = "/bin/", *curr = argv[0];
	size_t n = MAX_INPUT_LENGTH;
	int bytes_read;

	bytes_read = _read(&lineptr, &n);
	if (bytes_read == -1)
	{
		perror(curr);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	argc = 0;
	_strtoarr(argv, lineptr, argc);
	if (handle_exceptional_inputs(curr, argv, lineptr) == 1)
		exit(EXIT_SUCCESS);
	argv[0] = _charfinder(argv[0], '/') != 1 &&
		_strlen(argv[0]) > 0 ? _strcat(new, argv[0]) : argv[0];
	if (access(argv[0], X_OK) == 0)
		_fork(curr, argv, env);
	else
	{
		_strcpy(argv[0], "/bin/");
		perror(curr);
	}
	free(lineptr);
}
