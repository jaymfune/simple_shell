#include "main.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static size_t buffer_index = 0;
static size_t buffer_size = 0;

char *get_line()
{
	char *line = NULL;
	size_t line_size = 0;
	size_t line_length = 0;
	int c;

	while (1)
	{
		/* If the buffer is empty, refill it. */
		if (buffer_index >= buffer_size)
		{
			buffer_size = fread(buffer, 1, BUFFER_SIZE, stdin);
			buffer_index = 0;
		}

		/* If we've reached the end of the input, break. */
		if (buffer_size == 0)
		{
			if (line_length == 0)
			{
				free(line);
				return (NULL);
			}
			else
			{
				break;
			}
		}

		/* Read a character from the buffer. */
		c = buffer[buffer_index++];

		/* If we've reached the end of a line, break. */
		if (c == '\n')
		{
			break;
		}

		/* Allocate more space for the line if needed. */
		if (line_length + 1 >= line_size)
		{
			line_size += BUFFER_SIZE;
			line = realloc(line, line_size);
		}

		/* Append the character to the line. */
		line[line_length++] = c;
	}

	/* Null-terminate the line. */
	if (line_length > 0)
	{
		line[line_length] = '\0';
	}

	return (line);
}
