#include "kshell.h"
/**
 * get_exit_stat - function that takes the status value from wait
 * and returns the exit number
 * @stat: stat number obtained from wait
 * Return: error number
 */

int get_exit_stat(int stat)
{
	if (stat == 256)
	{
		return (1);
	}
	if (stat == 512)
		return (2);
	else
		return (0);
}
/**
 * check_exit - function that executes exit if line is exit
 * and will free the line and array of string argument
 * @exit_status: exit number
 * @av: argument strings tokenized from line
 * @line: line string to free
 * Return: nothing
 */
void check_exit(int exit_status, char **av, char *line)
{
	if (_strncmp(av[0], "exit", _strlen("exit")) == 0)
	{
		free_all(line, av);
		exit(exit_status);
	}
	else
		return;
}
