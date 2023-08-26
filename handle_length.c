#include "main.h"

/**
 * handle_length - Calculates the length to cast the argument
 * @format: Formatted string in which to print the arguments
 * @p: a pointer to an integer representing the index
 * Return: Length
 */

int handle_length(const char *format, int *p)
{
	int crnt_index = *p + 1;
	int length = 0;

	switch (format[crnt_index])
	{
		case 'l':
			length = L_LONG;
			break;
		case 'h':
			length = L_SHORT;
			break;
		default:
			*p = crnt_index - 1;
			break;
	}

	if (length != 0)
		*p = crnt_index;

	return (length);
}
