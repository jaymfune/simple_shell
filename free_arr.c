#include "shell.h"

/**
 * free_arr - free array.
 * @arr: str array to be freed.
 *
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
