#include "main.h"

/******************PRINTS POINTER*********************/

/**
 *
 *
 *
 *
 *
 *
 */

int pointer_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)
{
	char extra_char = 0, padding_char = ' ';
	int index = BUFFER_SIZE -2, length = 2, padding_start = 1;
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
		length++;
	}

	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		padding_char = '0';
	if (format_flags & FLAG_PLUS)
		extra_char = '+', length++;
	else if (format_flags & FLAG_SPACE)
		extra_char = ' ', length++;
	index++;

	return (write_custom_pointer(buffer_output, index, length, format_flags, padding_char, extra_char, padding_start));
}

/*************PRINTS NON-PRINTABLE CHARACTERS***************/

/**
 *
 *
 *
 *
 *
 *
 *
 */

int non_printable_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)
{
	int j = 0; hex_offset = 0;
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
 *
 *
 *
 *
 *
 */

int reverse_print(va_list args, char buffer_output[], int format_flags, int width, int precision,int length)

{
	char *input_str;
	int j, char_count = 0;

	UNUSED(buffet_output);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(length);

	input_str = va_arg(args, char *);

	if (input_str == NULL)
	{
		UNUSED(precision);

		input_str = "nullstring";
	}

	for (j = 0; input_str[j]; j++);

	for (j = j - 1; j >= 0; j--)
	{
		char reversed_char = input_str[j];

		write(1, &reversed_char, 1);
		char_count++;
	}

	return char_count;
}

/*****************PRINTS STRING IN ROT13******************/

/**
 *
 *
 *
 *
 *
 *
 */

int rot13_encoded_string_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)
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
