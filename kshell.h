#ifndef KSHELL_H
#define KSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

/*kshell.c*/
void check_prompt(void);
void check_EOF(ssize_t num_read, char *line);
char *check_input(char *cmd, char **env);
int pgm_go(char *argv0, char **av, char **env, int cmd_num);

/*avtok.c*/
unsigned int num_words(char *line, char delim);
char **line_to_av(char *line);

/*dir_helpers.c*/
unsigned int get_num_dir(char *dir);
char *get_dir_cmd(char *dir, char *cmd);
char **get_dir(char **env);

/*env_helpers.c*/
char *_getenv(const char *name, char **env);
void show_env(char **env, char **av);

/*error.c*/
int _putchar(char c);
char *convert(long int num, int base);
int err_not_found(char *argv0, char *av0, int cmd_num);

/*exit_helpers.c*/
int get_exit_stat(int stat);
void check_exit(int exit_status, char **av, char *line);

/*execute.c*/
int execute(char **av, char **env, char *fname);
/*this is for handling ctrl - c*/
void sigintHandler(int sig_num);
int check_spc_nl(char *line);
int check_builtin(char *av0);
void do_builtin(char **av, char **env);


/*free_mem.c*/
void free_upto_n(char **av, unsigned int n);
void free_av(char **cmds);
void free_all(char *line, char **av);
void free3(char *line, char **av, char *fn);

/*str_helpers.c*/
int _strncmp(const char *s1, const char *s2, size_t n);
unsigned int _strlen(char *s);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);

/*cd_helpers.c*/
int do_cd(char **av, char **env);
int go_here(char **av);
#endif /*KSHELL_H */
