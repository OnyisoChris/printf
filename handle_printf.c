#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @index: index
 * @args: List of arguments to be printed.
 * @buffer_output: Buffer array to handle print.
 * @format_flags: Calculates active flags
 * @width: handle width.
 * @precision: Precision specification
 * @length: Length specifier
 * Return: 1 or 2;
 */

int handle_print(const char *format, int *index, va_list args,
		char buffer_output[], int format_flags, int width,
		int precision, int length)
{
	int x = 0, unknown_len = 0, chars_prnt = -1;

	format format_type[] = {
		{'c', char_print}, {'s', string_print}, {'%', percent_print},
		{'i', int_print}, {'d', int_print}, {'b', binary_print},
		{'u', unsigned_print}, {'o', octal_print}, {'x', hexadecimal_print},
		{'X', hexa_upper_print}, {'p', pointer_print}, {'S', non_printable_print},
		{'r', reverse_print}, {'R', rot13_encoded_string_print}, {'\0', NULL}
	};
	while (format_type[x].format != '\0')
	{
		if (format[*index] == format_type[x].format)
			return (format_type[x].function(args, buffer_output,
					format_flags, width, precision, length));
		x++;
	}
	if (format_type[x].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &format[*index], 1);
		return (unknown_len);
	}
	return (chars_prnt);
}
