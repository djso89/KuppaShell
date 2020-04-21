#include "kshell.h"
/**
 * num_words - a function that returns the number of strings
 * broken up by delimiter character
 * @line: string from getline
 * @delim: delimiter character
 * Return: number of strings
 */
unsigned int num_words(char *line, char delim)
{
	int fldelim = 0;
	unsigned int wc = 0;

	while (*line)
	{
		if (*line == delim)
			fldelim = 0;
		else if (fldelim == 0)
		{
			fldelim = 1;
			wc++;
		}
		++line;
	}
	return (wc);
}
/**
 * line_to_av - a function that converts line string from getline in
 * array of strings.
 * @line: line from getline
 * Return: array of strings. NULL if fails.
 */
char **line_to_av(char *line)
{
	char **av;
	unsigned int wcnt;
	unsigned int i = 0;
	char *line_cp;
	char *word;

	line[_strlen(line) - 1] = '\0';
	line_cp = _strdup(line);
	if (!line_cp)
		return (NULL);
	wcnt = 0; /*start tokenizing and store into av format*/
	wcnt = num_words(line, ' ');
	av = malloc(sizeof(char *) * (wcnt + 1));
	if (!av)
	{
		free(line_cp);
		return (NULL);
	}
	word = strtok(line_cp, " ");
	i = 0;
	while (word)
	{
		av[i] = _strdup(word);
		if (av[i] == NULL)
		{
			free_upto_n(av, i);
			return (NULL);
		}
		word = strtok(NULL, " ");
		i++;
	}
	free(line_cp);
	av[i] = NULL;
	return (av);
}
