#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @index: index
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @format_flags: Calculates active flags
 * @width: handle width.
 * @precision: Precision specification
 * @length: Length specifier
 * Return: 1 or 2;
 */

int handle_print(const char *format, int *index, va_list list, char buffer[],
int format_flags, int width, int precision, int length)
{
	int x = 0, unknown_len = 0, chars_prnt = -1;

	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	while (format_types[x].format != '\0')
	{
		if (format[*index] == format_types[x].format)
			return (format_types[i].function(list, buffer,
					format_flags, width, precision, length));
		x++;
	}
	if (format_types[x].format == '\0')
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
