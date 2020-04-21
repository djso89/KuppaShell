#include "kshell.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On Success 1
* On error, -1 is returned, and errno is set appropriately
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 *
 * Return: string
 */
char *convert(long int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * err_not_found - function that prints the effor message if
 * invalid command is pressed
 * @argv0: object name from argv[0]
 * @av0: filename from av[0]
 * @cmd_num: command number to print
 * Return: exit_status when not found
 */
int err_not_found(char *argv0, char *av0, int cmd_num)
{
	write(STDERR_FILENO, argv0, _strlen(argv0));
	write(STDERR_FILENO, ":", 1);
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, convert(cmd_num, 10), _strlen(convert(cmd_num, 10)));
	write(STDERR_FILENO, ":", 1);
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, av0, _strlen(av0));
	write(STDERR_FILENO, ": not found\n", 12);
	return (127);
}
