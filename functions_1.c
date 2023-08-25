#include "main.h"

/***************PRINTS CHARACTER***********************/

/**
 * char_print - Formats and writes character to buffer
 * @args: argument list
 * @buffer_output: buffer for writing formatted character
 * @format_flags: for formatting flags
 * @width: minimum width of field
 * @precision: precision value
 * @length: length of the specifier
 * Return: Number of characters written
 */

int char_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int length)
{
	char c = va_arg(args, int);

	return (format_and_write_char(c, buffer_output,
				format_flags, width, precision, length));
}

/************************PRINTS STRINGS*******************/

/**
 * string_print - Prints a string
 * @args: The va_list containing the string argument
 * @buffer_output: The buffer to store the output
 * @format_flags: The formatting flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @length: The length specifier
 *
 * Return: Number of characters printed
 */

int string_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int length)
{
	int str_length = 0, j;
	char *str_data = va_arg(args, char *);

	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

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
 * percent_print - Prints the percent character
 * @args: The va_list (unused)
 * @buffer_output: The buffer to store the output (unused)
 * @format_flags: The formatting flags (unused)
 * @width: The width specifier (unused)
 * @precision: The precision specifier (unused)
 * @length: The length specifier (unused)
 *
 * Return: Number of characters printed
 */

int percent_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int length)
{
	UNUSED(args);
	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	char percent_character = '%';

	int write_chars = write(1, &percent_character, 1);

	return (write_chars);
}

/****************************PRINTS INTEGER*******************/

/**
 * int_print - Prints an integer in decimal format
 * @args: The va_list containing the integer argument
 * @buffer_output: The buffer to store the output
 * @format_flags: The formatting flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Number of characters printed
 */

int int_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int size)
{
	int j = BUFFER_SIZE - 2;
	int negative_i = 0;
	long int num = va_arg(args, long int);
	unsigned long int n;

	num = modify_size(num, size);

	if (num == 0)
		buffer_output[j--] = '0';

	buffer_output[BUFFER_SIZE - 1] = '\0';
	n = (unsigned long int)num;

	if (num < 0)
	{
		n = (unsigned long int)(-1) * num;
		negative_i = 1;
	}

	while (n > 0)
	{
		buffer_output[j--] = (n % 10) + '0';
		n /= 10;
	}

	j++;

	return (formatted_number(negative_i, j, buffer_output,
			format_flags, width, precision, size));
}

/***************PRINTS BINARY***********************/

/**
 * binary_print - Prints an unsigned integer in binary format
 * @args: The va_list containing the integer argument
 * @buffer_output: The buffer to store the output
 * @format_flags: The formatting flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @length: The length specifier
 *
 * Return: Number of characters printed
 */

int binary_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length)
{
	unsigned int num, i, j, sum;
	unsigned int binary_dig[32];
	int print_count;

	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	num = va_arg(args, unsigned int);
	i = 2147483648;

	binary_dig[0] = num / i;

	for (j = 1; j < 32; j++)
	{
		i /= 2;
		binary_dig[j] = (num / i) % 2;
	}
	for (j = 0, sum = 0, print_count = 0; j < 32; j++)
	{
		sum += binary_dig[j];
		if (sum || j == 31)
		{
			char binary_char = '0' + binary_dig[j];

			write(1, &binary_char, 1);
			print_count++;
		}
	}
	return (print_count);
}
