#include "main.h"

/*****************PRINTS UNSIGNED NUMBER*****************/

/**
 *
 *
 *
 *
 *
 *
 */

int unsigned_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
	int j = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);

	n = size_unsigned_convert(n, size);

	if (n == 0)
		buffer_output[j--] = '0';

	buffer_output[BUFFER_SIZE -1] = '\0';

	while (n > 0)
	{
		buffer_output[j--] = (n % 10) + '0';
		n /= 10;
	}

	j++;

	return (unsigned_write(0, j, buffer_output, format_flags, width, precision, size));
}


/****************PRINTS UNSIGNED OCTAL NUMBER************/

/**
 *
 *
 *
 *
 *
 *
 *
 */

int octal_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
	int j = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int initial_n = n;

	UNUSED(width);

	n = unsigned_size_convert(n, size);

	if (n == 0)
		buffer_output[j--] = '0';

	buffer_output[BUFFER_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer_output[j--] = (n % 8) + '0';
		n /= 8;
	}

	if (format_flags & FLAG_MINUS && initial_n != 0)
		buffer_output[j--] = '0';

	j++;

	return (unsigned_octal_write(0, j, buffer_output, format_flags, field_width, precision, size);
}

/**********PRINTS UNSIGNED HEXADECIMAL NUMBER*****************/

/**
 *
 *
 *
 *
 *
 *
 */

int hexadecimal_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
return (hexa_print(args, "0123456789abcdef", buffer_output, format_flags, 'x', width, precision, size));
}

/*******PRINTS UNSIGNED HEXADECIMAL NUMBER IN UPPERCASE*******/

/**
 *
 *
 *
 *
 *
 *
 */

int hexa_upper_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int size)
{
return (hexa_print(args, "0123456789ABCDEF", buffer_output, format_flags, 'X', width, precision, size));
}

/***PRINTS HEXADEC IN UPPER OR LOWER CASE************/

/**
 *
 *
 *
 *
 *
 *
 */

int hexa_print(va_list args, char buffer_result[], int format_flags, int width, int precision, int size)
{
	int j = BUFFER_SIZE -2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int initial_n = n;

	UNUSED(width);

	n = size_convert(n, size);

	if (n == 0)
		buffer_result[j--] = '0';

	buffer_result[BUFFER_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer_result[j--] = hex_map[n % 16];
		n /= 16;
	}

	if (format_flags & FLAG_HASH && initial_n != 0)
	{
		buffer_result[j--] = 'x';
		buffer_result[j--] = '0';
	}

	j++;

	return (write_result(0, j, buffer_result, format_flags_width, precision, size));
}
