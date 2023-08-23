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
	if (isatty(STDIN_FILENO))
		handle_interactive(argc, argv, env);
	else
		handle_noninteractive(argc, argv, env);
	return (0);
}
