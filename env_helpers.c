#include "kshell.h"
/**
 * _getenv - function that gets the value of environment variable name
 * @name: environment variable string
 * @env: environment array of strings
 * Return: environment value string. if not found, return NULL
 */
char *_getenv(const char *name, char **env)
{
	char *env_name = NULL;
	unsigned int env_len;
	unsigned int i, j;
	int found;

	found = 0;
	i = 0;
	while (env[i])
	{
		for (j = 0, env_len = 0; env[i][j] != '='; j++)
		{
			env_len++;
		}
		env_name = malloc(sizeof(char) * (env_len + 1));
		if (!env_name)
			return (NULL);
		env_name = _strncpy(env_name, env[i], env_len);
		found = _strncmp(env_name, name, env_len);
		if (found == 0)
		{
			free(env_name);
			return (env[i]);
		}
		i++;
		free(env_name);
		env_name = NULL;
	}
	return (NULL);
}
/**
 * show_env - a function that displays environment
 * and frees array of arguments and line from getline
 * @env: environment array of strings
 * @av: array of argument strings
 * Return: Nothing
 */
void show_env(char **env, char **av)
{
	unsigned int i;

	i = 0;
	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_av(av);
}
