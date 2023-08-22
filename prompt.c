#include "main.h"

/**
 * prompt - handles getting user input
 * @outputtxt: text printed before getting input
 * @buffer: double pointer to user input
 * @n: size
 * Return: bytes read
 */
int prompt(char *outputtxt, char **buffer, size_t *n)
{
	int bytes_read;

	write(1, outputtxt, _strlen(outputtxt));
	bytes_read = _getline(buffer, n, stdin);
	if (bytes_read > 0)
		*(*buffer + (bytes_read - 1)) = '\0';
	return (bytes_read);
}
