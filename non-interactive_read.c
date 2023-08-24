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
 * handle_query - handles shell scripts
 * @argv: command line arguments
 * @env: double pointer to environmental variables
 * @curr: executing file
 * Return: void
*/
void handle_query(char *argv[], char **env, char *curr)
{
	char new[MAX_INPUT_LENGTH] = "/bin/";

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
