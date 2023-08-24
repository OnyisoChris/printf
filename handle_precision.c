#include "main.h"

/**
 * handle_precision - extract and calculates the precision for printing
 * @format: formatted string in which the arguments will be printed.
 * @p: A pointer to an integer that represents the current index in the format string.
 * @list: list of arguments
 * Return: Precision
 */

int handle_precision(const char *format, int *p, va_list list)
{
	int crnt_index = *p + 1;
	int precision = -1;

	switch (format[crnt_index])
	{
		case '.':
			break;
		default:
			return (precision);
	}
	precision = 0;
	for (crnt_index += 1; format[crnt_index] != '\0'; crnt_index++)
	{
		switch (format[crnt_index])
		{
			case '0' ... '9':
				precision *= 10;
				precision += format[crnt_index] - '0';
				break;
			case '*':
				crnt_index++;
				precision = va_arg(list, int);
				*p = crnt_index - 1;
				return (precision);
			default:
				*p = crnt_index - 1;
				return (precision);
		}
	}
	*p = crnt_index - 1;
	return (precision);
}

