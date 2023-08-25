#include "main.h"

/******************PRINTS POINTER*********************/

/**
 * pointer_print - prints hexadecimal represents of a pointer
 * @args: the va_list
 * @buffer_output: buffer to store the output
 * @format_flags: formatting flags
 * @width: The width specifier
 * @precision: precision specifier
 * @length: length specifier
 *
 * Return: number of characters printed
 */

int pointer_print(va_list args, char buffer_output[], int format_flags
		int width, int precision, int length)
{
	char extra_char = 0, padding_char = ' ';
	int index = BUFFER_SIZE - 2, calculated_length = 2, padding_start = 1;
	unsigned long n_address;
	char hex_digits[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(width);
	UNUSED(length);

	if (address == NULL)
		return (write(1, "(null)", 6));

	buffer_output[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	n_address = (unsigned long)address;

	while (n_address > 0)
	{
		buffer_output[index--] = hex_digits[n_address % 16];
		n_address /= 16;
		calculated_length++;
	}

	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		padding_char = '0';
	if (format_flags & FLAG_PLUS)
	{
		extra_char = '+';
		calculated_length++;
	}
	else if (format_flags & FLAG_SPACE)
	{
		extra_char = ' ';
		calculated_length++;
	}
	index++;

	return (write_custom_pointer(buffer_output, index, calculated_length,
				format_flags, padding_char, extra_char, padding_start));
}

/*************PRINTS NON-PRINTABLE CHARACTERS***************/

/**
 * non_printable_print - Print a string with non-printable
 * characters replaced by hex codes
 * @args: The va_list containing the argument (a string)
 * @buffer_output: The buffer to store the output
 * @format_flags: The formatting flags (unused)
 * @width: The width specifier (unused)
 * @precision: The precision specifier (unused)
 * @length: The length specifier (unused)
 *
 * Return: The number of characters printed
 */

int non_printable_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int length)
{
	int j = 0;

	hex_offset = 0;

	char *input_str = va_arg(args, char *);

	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	if (input_str == NULL)
		return (write(1, "(null)", 9));
	while (input_str[j] != '\0')
	{
		if (j_printable(input_str[j])
			buffer_output[j + hex_offset] = input_str[j];
		else
			hex_offset += append_hexa(input_str[j], buffer_output, j + hex_offset);

			j++;
	}
	buffer_output[j + hex_offset] = '\0';

	return (write(1, buffer_output, j + hex_offset));
}

/*******************PRINTS REVERSE***********************/

/**
 * reverse_print - Print a string in reverse order
 * @args: The va_list containing the argument (a string)
 * @buffer_output: The buffer to store the output (unused)
 * @format_flags: The formatting flags (unused)
 * @width: The width specifier (unused)
 * @precision: The precision specifier (unused)
 * @length: The length specifier (unused)
 *
 * Return: The number of characters printed
 */

int reverse_print(va_list args, char buffer_output[], int format_flags,
		int width, int precision, int length)

{
	char *input_str;
	int j, char_count = 0;

	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(length);

	input_str = va_arg(args, char *);

	if (input_str == NULL)
	{
		UNUSED(precision);

		input_str = "nullstring";
	}

	for (j = 0; input_str[j]; j++)
	{
		/**This loop is used to calculate the length of the string**/
	}

	for (j = j - 1; j >= 0; j--)
	{
		char reversed_char = input_str[j];

		write(1, &reversed_char, 1);
		char_count++;
	}

	return (char_count);
}

/*****************PRINTS STRING IN ROT13******************/

/**
 * rot13_encoded_string_print - Print a ROT13-encoded string
 * @args: The va_list containing the argument (a string)
 * @buffer_output: The buffer to store the output (unused)
 * @format_flags: The formatting flags (unused)
 * @width: The width specifier (unused)
 * @precision: The precision specifier (unused)
 * @length: The length specifier (unused)
 *
 * Return: The number of characters printed
 */

int rot13_encoded_string_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length)
{
	char temp;
	char *input_str;
	unsigned int k, l;
	int printed_count = 0;
	char mapping_from[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mapping_to[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	UNUSED(buffer_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	input_str = va_arg(args, char *);

	if (input_str == NULL)
		input_str = "(Empty)";

	for (k = 0; input_str[k]; k++)
	{
		for (l = 0; mapping_from[l]; l++)
		{
			if (mapping_from[l] == input_str[k])
			{
				temp = mapping_to[l];
				write(1, &temp, 1);
				printed_count++;
				break;
			}
		}
		if (!mapping_from[l])
		{
			temp = input_str[k];
			write(1, &temp, 1);
			printed_count++;
		}
	}
	return (printed_count);
}
