#include "shell.h"
/**
 * _fetchpath - Find the full path to an executable command.
 * @command: The name of the command.
 *
 * Return: allocated str containing full path, NULL if not found.
 */
char *_fetchpath(char *command)
{
	int i;
	char *path_env, *full_path, *directory;
	struct stat stt;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &stt) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	path_env = _getenvi("PATH");
	if (!path_env)
		return (NULL);

	directory = strtok(path_env, ":");
	while (directory)
	{
		full_path = malloc(_strlen(directory) + _strlen(command) + 2);
		if (full_path)
		{
			_strcpy(full_path, directory);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (stat(full_path, &stt) == 0)
			{
				free(path_env);
				return (full_path);
			}

			free(full_path);
			directory = strtok(NULL, ":");
		}
	}

	free(path_env);
	return (NULL);
}
