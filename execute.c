#include "shell.h"

void execute_command(char *user_input)
{
    char *args[MAX_ARGS];
    int i;
    pid_t pid;

    i = 0;
    args[i] = strtok(user_input, " \n");

    while (args[i] != NULL)
    {
        /* printf("Token: %s\n", args[i]); */
        i++;
        args[i] = strtok(NULL, " \n");
    }

    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0)
    {
        handle_exit();
    }

    /* Execute the command */
    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            perror("Command not found");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("Waitpid failed");
            exit(EXIT_FAILURE);
        }
    }
}