#include "kshell.h"
/**
 * free_av - Clear the cmds array of strings
 * @cmds: command strings
 * Return: Nothing
 */
void free_av(char **cmds)
{
	unsigned int i = 0;

	if (cmds == NULL)
		return;
	for (i = 0; cmds[i]; i++)
	{
		free(cmds[i]);
	}
	if (cmds[i] == NULL)
	{
		free(cmds[i]);
	}
	free(cmds);
}
/**
 * free_upto_n - used for checking malloc fail for char ** types
 * the n is the index of av there the malloc failed.
 * @av: array of strings
 * @n: index value of av where malloc failed occured
 * Return: Nothing
 */
void free_upto_n(char **av, unsigned int n)
{
	unsigned int i;

	for (i = 0; i <= n; i++)
	{
		free(av[i]);
	}
	free(av);
}
/**
 * free_all - free the line from getline and argument string array
 * @line: line string from getline
 * @av: argument string array
 * Return: Nothing
 */
void free_all(char *line, char **av)
{
	free(line);
	free_av(av);
}
/**
 * free3 - frees the line, av, and fn string from check_input
 * @line: string from getline
 * @av: array of strings tokenized from line
 * @fn: string from check_input
 * Return: nothing
 */
void free3(char *line, char **av, char *fn)
{
	free(line);
	free(fn);
	free_av(av);
}
