#include "shell.h"

/**
 * cget_line - Custom Get line that reads
 * string from stin
 * return: A ptr to allocated str containing the line
 *
 */

char *cget_line(void)
{
    char *line = NULL;
    size_t line_size = 0;
    ssize_t n;

    while (1)
    {
        if (buffer_pos == buffer_size)
        {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (buffer_size == 0)
            {
                if (line_size > 0)
                {
                    return line;
                }
                else
                {
                    free(line);
                    return (NULL);
                }
            }
            else if (buffer_size < 0)
            {
                perror("read");
                free(line);
                return (NULL);
            }
            buffer_pos = 0;
        }

        char c = buffer[buffer_pos++];

        if (c == '\n')
        {
            if (line == NULL)
            {
                line = (char *)malloc(line_size + 1);
            }
            else
            {
                line = (char *)realloc(line, line_size + 1);
            }

            if (line == NULL)
            {
                perror("malloc/realloc");
                return (NULL);
            }

            line[line_size] = '\0';
            return (line);
        }
        else
        {
            if (line == NULL)
            {
                line = (char *)malloc(1);
            }
            else
            {
                line = (char *)realloc(line, line_size + 1);
            }

            if (line == NULL)
            {
                perror("malloc/realloc");
                return (NULL);
            }

            line[line_size++] = c;
        }
    }
}