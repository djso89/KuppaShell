#include "kshell.h"

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
