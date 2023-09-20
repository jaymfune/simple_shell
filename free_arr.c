#include "shell.h"

/**
 * free_arr - free array.
 * @ary: str array to be freed.
 *
 */
void free_arr(char **ary)
{
	int i;

	if (!ary)
		return;

	for (i = 0; ary[i]; i++)
	{
		free(ary[i]);
		ary[i] = NULL;
	}

	free(ary);
	ary = NULL;
}
