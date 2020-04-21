#include "kshell.h"
int check_builtin(char *av0);
void do_builtin(char **av, char **env);
int do_cd(char **av, char **env);
/**
 * main - Entry Point
 * @argc: number of argument count.
 * @argv: array of argument strings
 * @env: environment array of strings
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL, **av;
	size_t n;
	ssize_t num_read;
	int exit_status = 0, spc_flag = 0, cmd_num = 0, isBlt = 0;
	(void)argc;

	check_prompt();
	while ((num_read = getline(&line, &n, stdin)) != EOF)
	{
		cmd_num++;
		spc_flag = check_spc_nl(line);
		if (spc_flag == 1)
		{
			spc_flag = 0;
			check_prompt();
			continue;
		}
		av = line_to_av(line);
		check_exit(exit_status, av, line);
		isBlt = check_builtin(av[0]);
		if (isBlt)
		{
			isBlt = 0;
			do_builtin(av, env);
			check_prompt();
			continue;
		}
		/*look through directories and execute cmd*/
		exit_status = pgm_go(argv[0], av, env, cmd_num);
		check_prompt();
	}
	check_EOF(num_read, line);
	return (exit_status);
}
int check_builtin(char *av0)
{
	if (_strncmp(av0, "env", _strlen("env")) == 0)
		return (1);
	if (_strncmp(av0, "cd", _strlen("cd")) == 0)
		return (1);
	return (0);
}
void do_builtin(char **av, char **env)
{
	if (_strncmp(av[0], "env", _strlen("env")) == 0)
	{
		show_env(env, av);
		return;
	}
	if (_strncmp(av[0], "cd", _strlen("cd")) == 0)
	{
		do_cd(av, env);
		return;
	}
}
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
	free_av(av);
	return (-1);
}
