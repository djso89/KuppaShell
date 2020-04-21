#include "kshell.h"
/**
 * check_prompt - a function that print the prompt as long as
 * file descriptor refers to a terminal (TTY)
 * Return: Nothing
 */
void check_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "KuppaShell$ ", 12);
	}
}
/**
 * check_input - a function that checks if filename is valid
 * if the filename is found, returns appended string
 * of address and / and cmd
 * @cmd: the user command such as ls pwd
 * @env: envirionment variable for getting direction from PATH env. variable
 * Return: appended string of directory and cmd with / in between.
 * if fails, it returns NULL
 */
char *check_input(char *cmd, char **env)
{
	char *dir_cmd, **dir_av;
	unsigned int i = 0;
	struct stat st;

	if (cmd[0] == '/' && stat(cmd, &st) == 0)
		return (_strdup(cmd));
	if (cmd[0] == '.' && cmd[1] == '/' && stat(cmd, &st) == 0)
		return (_strdup(cmd));
	if (cmd[0] == '.' && cmd[1] == '.' && stat(cmd, &st) == 0)
		return (_strdup(cmd));
	dir_av = get_dir(env);
	if (!dir_av)
		return (NULL);
	while (dir_av[i])
	{
		dir_cmd = get_dir_cmd(dir_av[i], cmd);
		if (!dir_cmd)
		{
			free_av(dir_av);
			return (NULL);
		}
		if (stat(dir_cmd, &st) == 0)
		{
			free_av(dir_av);
			return (dir_cmd);
		}
		free(dir_cmd);
		dir_cmd = NULL;
		i++;
	}
	free_av(dir_av);
	return (NULL);
}
/**
 * check_EOF - a function that takes num_read from getline
 * and see if ctrl-D is pressed. if ctrl+D is pressed, it checks if
 * stdin file descriptor is on terminal.
 * @num_read: number of bytes read from getline
 * @line: line string to free
 * Return: nothing
 */
void check_EOF(ssize_t num_read, char *line)
{
	if (num_read == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	free(line);
}
/**
 * pgm_go - function that searches user command in directories
 * obtained from PATH environment variable, and execute if user command
 * exist in the one of directories
 * @argv0: object file name
 * @av: argument strings
 * @env: environment strings
 * @cmd_num: command number to print
 * Return: program exit status
 */
int pgm_go(char *argv0, char **av, char **env, int cmd_num)
{
	char *filename;
	int exit_status = 0;

	filename = check_input(av[0], env);
	if (filename == NULL)
		exit_status = err_not_found(argv0, av[0], cmd_num);
	else
	{
		exit_status = 0;
		free(av[0]);
		av[0] = _strdup(filename);
		exit_status = execute(av, env, argv0);
	}
	free_all(filename, av);
	return (exit_status);
}
