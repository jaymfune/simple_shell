#include "main.h"

#define MAX_ARGS 10

int main()
{
	char *prompt = "($)"; /* Prompt to print to terminal */

	/* To store the address of the buffer holding the user input */
	char *user_input; 
	size_t n = 0; /* to store alloacted size in bytes */
	ssize_t input_length;
	char* args[MAX_ARGS];
	int i;
	pid_t pid;

	while (1)
	{
		printf("%s", prompt);
		input_length  = getline(&user_input, &n, stdin);

		/* printf("%ld", input_length); */

		/* Handle Ctrl+D (end-of-file condition) or other input errors */
		if (input_length  == -1)
		{
			printf("Exiting shell....\n");
			free(user_input);
			return(-1);
		}
		else
		{
			/**
			  * Break the user input into separate commands
			  * to execute the commands
			  */
			i = 0;
			args[i] = strtok(user_input, " \n");

			while (args[i] != NULL)
			{
				printf("Token: %s\n", args[i]);
				i++;

				/* get next the next string */
				args[i] = strtok(NULL, " \n");
			}
			args[i] = NULL;

			/* Handle the exit built-in command */
			if (strcmp(args[0], "exit") == 0)
			{
				printf("Exiting shell....\n");
				return (0);
			}

			/*Execute the command */
			pid = fork();
			if (pid == -1)
			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("Command not found");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int status;
				if (waitpid(pid, &status, 0) == -1)
				{
					perror("Waitpid failed");
					exit(EXIT_FAILURE);
				}
			}
		}
		

		printf("%s", user_input);
	}

	free(user_input);

	return (0);
}
