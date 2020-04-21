#include "kshell.h"


/**
 * _strncmp - compares two strings
 * @s1: pointer to dest string to copy, starting from index 0
 * @s2: pointer to string to to be copied
 * @n: length up to nth character of s2
 * Return: zero, -, or + int
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
		if (*s1++ != *s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (0);
}


/**
 * _strlen - returns the length of a string
 * @s: pointer to character
 * Return: int length of string
 */

unsigned int _strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strdup - return pointer to new allocated space with duplicate string
 * @str: pointer to string input to copy
 * Return: pointer to duplicated string, otherwise NULL
 */

char *_strdup(char *str)
{
	char *ptr;
	int size, c;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	ptr = malloc(size * sizeof(char));

	if (ptr == NULL)
		return (NULL);

	for (c = 0; str[c]; c++)
		ptr[c] = str[c];

	ptr[c] = '\0';

	return (ptr);
}

/**
 * char *_strncpy - copies a string from src to dest
 * @dest: pointer to dest string to copy, starting from index 0
 * @src: pointer to string to to be copied
 * @n: number of chars to copy/size of dest
 * Return: pointer to dest with edited string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
