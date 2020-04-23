#include "kshell.h"
/**
 * do_cd - function that changes directory
 * @av: argument strings
 * @env: environment strings
 * Return: 0 if successful changing dir. otherwise, -1
 */
int do_cd(char **av, char **env)
{
	char *path, *path_cpy, *path_tok;
	int isChanged = 0;

	if (av[1] == NULL || _strncmp(av[1], "~", 1) == 0)
	{
		path = _getenv("HOME", env);
		path_cpy = _strdup(path);
		path_tok = strtok(path_cpy, "=");
		path_tok = strtok(NULL, "\n");
		isChanged = chdir(path_tok);
		free(path_cpy);
		free_av(av);
		return (isChanged);
	}
	if (_strncmp(av[1], "..", 2) == 0)
	{
		isChanged = chdir("..");
		free_av(av);
		return (isChanged);
	}
	if (_strncmp(av[1], "-", 1) == 0)
	{
		path = _getenv("OLDPWD", env);
		path_cpy = _strdup(path);
		path_tok = strtok(path_cpy, "=");
		path_tok = strtok(NULL, "\n");
		isChanged = chdir(path_tok);
		free(path_cpy);
		free_av(av);
		return (isChanged);
	}
	else
		isChanged = go_here(av);
	return (-1);
}
/**
 * go_here - a function that changes directory if filename is
 * valid
 * @av: argument string
 * Return: 0 if change directory is success, otherwise, 0
 */
int go_here(char **av)
{
	int isChanged = 0;

	if (access(av[1], F_OK) == 0)
	{
		isChanged = chdir(av[1]);
		free_av(av);
		return (isChanged);
	}
	else
	{
		perror(av[1]);
		free_av(av);
	}
	return (-1);
}
