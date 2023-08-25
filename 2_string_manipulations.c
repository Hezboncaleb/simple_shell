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
/**
 * _strpbrk - locates the first occurrence in the string s
 * of any of the bytes in the string accept
 * @s: char pointer
 * @accept: char pointer
 * Return:  pointer to the byte in s that matches
 * one of the bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j;
	int len1 = _strlen(s), len2 = _strlen(accept);
	int res = len1, ispresent = 0;

	while (i < len2)
	{
		for (j = 0; j < len1; j++)
		{
			if (s[j] == accept[i])
			{
				ispresent = 1;
				res = j <= res ? j : res + 0;
			}
		}
		i++;
	}
	if (ispresent == 1)
		return (s + res);
	else
		return (NULL);
}
