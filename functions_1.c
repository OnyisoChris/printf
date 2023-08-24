#include "main.h"

/***************PRINTS CHARACTER***********************/

/**
 * char_print - Formats and writes character to buffer
 * @args: argument list
 * @buffer_output: buffer for writing formatted character
 * @format_flags: for formatting flags
 * @width: minimum width of field
 * @precision: precision value
 * @size: size of the specifier
 * Return: Number of characters written
 */

int char_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (format_and_write_char(c, buffer_output, format_flags, width, precision, size);
}

/************************PRINTS STRINGS*******************/

/**
 *
 *
 *
 *
 *
 *
 *
 */

int string_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
	int str_length = 0, j;
	char *str_data = va_arg(args, char *);

	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str_data == NULL)
	{
		str_data = "(null)";
		if (precision > 5)
			str_data = " ";
	}

	while (str_data[str_length] != '\0')
		str_length++;

	if (precision >= 0 && precision < str_length)
		str_length = precision;

	if (width > str_length)
	{
		if (format_flags & FLAG_MINUS)
		{
			write(1, &str_data[0], str_length);
			for (j = width - str_length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - str_length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str_data[0], str_length);
			return (width);
		}
	}
	return (write(1, str_data, str_length));
}

/************************PRINTS PERCENT SIGN****************/

/**
 *
 *
 *
 *
 *
 *
 */

int percent_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	char percent_character = '%';

	int write_chars = write(1, &percent_character, 1);

	return write_chars;
}
