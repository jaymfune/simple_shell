#include "shell.h"

/**
 * out_error - Prints an error message to stderr
 * @program_name: The name of the program.
 * @command: The command that caused the error.
 * @index: The index of the command.
 *
 * Description: This function prints an error
 * message to the standard error
 * stream (stderr) in the format:
 * "program_name: index: command: not found\n".
 */
void out_error(char *program_name, char *command, int index)
{
	char *index_str, message[] = ": not found\n";

	index_str = _itoa(index);

	write(STDERR_FILENO, program_name, _strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index_str, _strlen(index_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));
	free(index_str);
}

/**
 * _itoa - Converts an integer to a string
 * @n: The integer to be converted.
 * Return: A pointer to the resulting string.
 *
 * Description: This function converts an integer to a string and returns
 * a pointer to the newly created string.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * rev_str - Reverses a string in-place
 * @str: The string to be reversed.
 * @len: The length of the string.
 *
 * Description: This function reverses a string in-place.
 */
void rev_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
