#include "main.h"

/**
 * handle_env - handles the printing of environmental variables
 * Return: void
 */

void handle_env(void)
{
	char *arr_index[] = {"USER", "LANGUAGE", "SESSION",
		"COMPIZ_CONFIG_PROFILE", "SHLVL", "HOME",
		"C_IS", "DESKTOP_SESSION", "LOGNAME", "TERM", "PATH", "DISPLAY"};
	char *new_env[12];
	int i, j;

	for (j = 0; j < 12; j++)
	{
		if (j == 2 || j == 3)
			new_env[j] = getenv(arr_index[7]);
		else if (j == 6)
			new_env[j] = "Fun_:)";
		else
			new_env[j] = getenv(arr_index[j]);
	}
	for (i = 0; i < 12; i++)
	{
		write(1, arr_index[i], _strlen(arr_index[i]));
		write(1, "=", 1);
		write(1, new_env[i], _strlen(new_env[i]));
		write(1, "\n", 1);
	}
}
