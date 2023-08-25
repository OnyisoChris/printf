#include "main.h"

/**
 * handle_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @p: a pointer to an integer representing the current index
 * @list: list of arguments
 * Return: width
 */

int handle_width(const char *format, int *p, va_list list)
{
	int crnt_index = *p + 1;
	int width = 0;

	while (format[crnt_index] != '\0')
	{
		if (is_digit(format[crnt_index]))
		{
			width *= 10;
			width += format[crnt_index] - '0';
		}
		else if (format[crnt_index] == '*')
		{
			crnt_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		crnt_index++;
	}
	*p = crnt_index - 1;

	return (width);
}
