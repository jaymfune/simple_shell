#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "($)"; /* Prompt to print to terminal */

	/* To store the address of the buffer holding the user input */
	char *user_input; 
	size_t n = 0; /* to store alloacted size in bytes */

	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&user_input, &n, stdin);
	printf("%s", user_input);

	return (0);
}
