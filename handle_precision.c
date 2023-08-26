#include "main.h"

/**
 * handle_precision - extract and calculates the precision for printing
 * @format: formatted string in which the arguments will be printed.
 * @p: Pointer to an integer representing current index in format string.
 * @args: list of arguments
 * Return: Precision
 */

int handle_precision(const char *format, int *p, va_list args)
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
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				precision *= 10;
				precision += format[crnt_index] - '0';
				break;
			case '*':
				crnt_index++;
				precision = va_arg(args, int);
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
