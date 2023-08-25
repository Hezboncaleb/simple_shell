#include "main.h"

/**
 * _strtoarr - generates tokens from string based on delimiter
 * @arr: array to store the tokens
 * @buffer: holds the input
 * @num: integer
 * @delimiter: delimiter
 * Return: void
 */

void _strtoarr(char *arr[], char *buffer, int num, char *delimiter)
{
	char *token;

	token = _strtok(buffer, delimiter);
	while (token != NULL)
	{
		if (_strlen(token) > 0)
		{
			arr[num] = token;
			num++;
		}
		token = _strtok(NULL, delimiter);
	}
	arr[num] = NULL;
}

/**
 * _strlen -  a function that returns the length of a string.
 * @s: An input string
 * Return: Nothing
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);

}
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0, if the s1 and s2 are equal, a negative value if
 * s1 is less than s2, a positive value if s1 is greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	int cmpstr, i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			cmpstr = s1[i] - s2[i];
			break;
		}
		cmpstr = s1[i] - s2[i];
		i++;
	}
	return (cmpstr);
}

/**
 * _strtoint - converts a string to an int
 * @str: string to be converted
 * Return: resulting integer
 */

int _strtoint(char *str)
{
	int res = 0, len = _strlen(str) - 1;
	int i, j = 1;

	i = len;

	while (i >= 0)
	{
		res += (str[i] - '0') * j;
		i--;
		j *= 10;
	}
	return (res);
}

/**
 * _strtok - generates tokens from string based on delimiter
 * @buffer: holds the input
 * @delimiter: delimiter
 * Return: pointer to new array
 */

char *_strtok(char *buffer, char *delimiter)
{
	static char *end;
	char *start;
	int i;

	if (buffer == NULL)
	{
		if (end == NULL || *end == '\0')
			return (NULL);
		start = end;
	}
	else
	{
		end = buffer;
		start = buffer;
	}
	while (end)
	{
		if (*end == '\0')
		{
			end = NULL;
			return (start);
		}
		i = 0;
		while (delimiter[i])
		{
			if (*end == delimiter[i])
			{
				*end = '\0';
				end = end + 1;
				return (start);
			}
			i++;
		}
		end++;
	}
	return (start);
}
