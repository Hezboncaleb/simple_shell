#include "main.h"

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: destination string
 * @src: source string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (*(src + len) != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _charfinder - locates a character in a string.
 * @s: char pointer
 * @c: char to be located
 * Return: 1 if char is found 0 otherwise
 */

int _charfinder(char *s, char c)
{
	int index = 0;

	while (s[index] != '\0')
	{
		if (s[index] != c)
			index++;
		else
			break;
	}
	if (s[index] != c)
		return (0);
	else
		return (1);
}
/**
 * _strcat - concatenates two strings.
 * @src: string to be appended
 * @dest: destination char pointer
 * Return: pointer to the dest string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (*(dest + i) != '\0')
	{
		i++;
	}
	j = 0;
	while (*(src + j) != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);

}
