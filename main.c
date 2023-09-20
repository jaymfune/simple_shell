#include "shell.h"

/**
 * main - Entry point of the shell.
 * @ac: Argument count.
 * @argv: Array of command-line arguments.
 *
 * Return: Always returns 0.
 */
int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, ind = 0;

	(void)ac;

	while (1)
	{
		/* Read a line of input from the user. */
		line = read_line();
		if (line == NULL)
		{
			/**
			 * If the input is null and we are in a terminal,
			 * print a newline and exit.
			 */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		ind++;

		/* Tokenize the input line to get individual commands. */
		command = tokenizer(line);
		if (!command)
			continue;

		/* Check if the command is a built-in shell command. */
		if (builtin_check(command[0]))
			builtin_hnd(command, argv, status, ind); /* Handle built-in commands. */
		else
			status = _execute(command, argv, ind); /* Execute external commands. */
	}
}
