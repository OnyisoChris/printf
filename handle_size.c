#include "main.h"

/**
 * handle_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @p: a pointer to an integer representing the index
 * Return: Size
 */

int handle_size(const char *format, int *p)
{
	int crnt_index = *p + 1;
	int size = 0;

	switch (format[crnt_index])
	{
		case 'l':
			size = SIZE_LONG;
			break;
		case 'h':
			size = SIZE_SHORT;
			break;
		default:
			*P = crnt_index - 1;
			break;
	}

	if (size != 0)
		*P = crnt_index;

	return (size);
}
