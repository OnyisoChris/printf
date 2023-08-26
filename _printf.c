#include "main.h"

void print_buff(char buffer_output[], int *buffer_i);

/**
 * _printf - print an output and write it to standard output
 * @format: is a character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int x, prnt = 0, chars_prnt = 0;
	int format_flags, width, precision, length, buffer_i = 0;

	va_list args;
	char buffer_output[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer_output[buffer_i++] = format[x];
			if (buffer_i == BUFFER_SIZE)
				print_buff(buffer_output, &buffer_i);
			chars_prnt++;
		}
		else
		{
			print_buff(buffer_output, &buffer_i);
			format_flags = handle_flags(format, &x);
			width = handle_width(format, &x, args);
			precision = handle_precision(format, &x, args);
			length = handle_length(format, &x);
			++x;
			prnt = handle_print(format, &x, args, buffer_output,
				format_flags, width, precision, length);
			if (prnt == -1)
				return (-1);
			chars_prnt += prnt;
		}
	}

	print_buff(buffer_output, &buffer_i);

	va_end(args);

	return (chars_prnt);
}

/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buffer_output: Array of chars
 * @buffer_i: Index at which to add next char, represents the length.
 */
void print_buff(char buffer_output[], int *buffer_i)
{
	if (*buffer_i > 0)
		write(1, &buffer_output[0], *buffer_i);

	*buffer_i = 0;
}
