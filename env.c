#include "main.h"

/**
 * handle_env - handles the printing of environmental variables
 * @envp: double pointer to env
 * Return: void
 */

void handle_env(char **envp)
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		write(1, *env, _strlen(*env));
		write(1, "\n", 1);
	}
}
