#include "shell.h"

/**
  * main - shell entry point.
  * Return: Always returns 0.
  */

int main(void)
{
	char *prompt = "($)"; /* Prompt to print to the terminal */
	char *user_input;
	size_t n = 0;
	ssize_t input_length;

	while (1)
	{
		printf("%s", prompt);
		input_length = getline(&user_input, &n, stdin);

		/* printf("%ld", input_length); */

		/* Handle Ctrl+D (end-of-file condition) or other input errors */
		if (input_length == -1)
		{
			printf("Exiting shell....\n");
			free(user_input);
			return (-1);
		}
		else
		{
			execute_command(user_input);
		}

		printf("%s\n", user_input);
	}

	free(user_input);

	return (0);
}
