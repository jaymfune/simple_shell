#include "shell.h"

/**
 * tokenizer - it breaks a string up into individual
 * word eg cat main.c into token 0: cat and
 * token 1: main.c.
 * @line: str to be tokenized.
 *
 * Return: array of strs containing tokens, NULL if fail.
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);

		i++;
	}

	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
