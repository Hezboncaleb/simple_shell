#include "main.h"

/**
 * _getline - gets user input
 * @buffer: stores the user input
 * @n: size
 * @stream: source of user input
 * Return: bytes read
 */

size_t _getline(char **buffer, size_t *n, FILE *stream)
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
	bytes_read = read(_fileno(stream), *buffer, *n);
	return (bytes_read);
}

/**
 * _fileno - check and reset stream status
 * @stream: source
 * Return: status
 */

int _fileno(FILE *stream)
{
	if (stream == stdin)
	{
		return (1);
	}
	return (1);
}
