#include "main.h"

/**Write Char **/
/**
 * write_char_handle - Prints a string
 * @c: type of character
 * @buffer_output: buffer array to handle print
 * @format_flags: handles active flags.
 * @width: handles width.
 * @precision: specifies precision
 * @length: specifies length
 *
 * Return: number of printed characters
 */
int write_char_handle(char c, char buffer_output[],
	int format_flags, int width, int precision, int length)
{
	int x = 0;
	char pdn = ' ';

	UNUSED(precision);
	UNUSED(length);

	if (format_flags & FLAG_ZERO)
		pdn = '0';

	buffer_output[x++] = c;
	buffer_output[x] = '\0';

	if (width > 1)
	{
		buffer_output[BUFFER_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer_output[BUFFER_SIZE - x - 2] = pdn;

		if (format_flags & FLAG_MINUS)
			return (write(1, &buffer_output[0], 1) +
					write(1, &buffer_output[BUFFER_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer_output[BUFFER_SIZE - x - 1], width - 1) +
					write(1, &buffer_output[0], 1));
	}

	return (write(1, &buffer_output[0], 1));
}

/**Write digit**/
/**
 * write_digit_handle - Prints a number
 * @is_negative: checks whether a number is negative
 * @index: index
 * @buffer_output: buffer array to handle print
 * @format_flags: handles active flags
 * @width: handles width
 * @precision: specifies precision
 * @length: specifies length
 *
 * Return: number of printed characters
 */
int write_digit_handle(int is_negative, int index, char buffer_output[],
	int format_flags, int width, int precision, int length)
{
	int len = BUFFER_SIZE - index - 1;
	char pdn = ' ', ex_ch = 0;

	UNUSED(length);

	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		pdn = '0';
	if (is_negative)
		ex_ch = '-';
	else if (format_flags & FLAG_PLUS)
		ex_ch = '+';
	else if (format_flags & FLAG_SPACE)
		ex_ch = ' ';

	return (write_digit(index, buffer_output, format_flags, width, precision,
		len, pdn, ex_ch));
}

/**
 * write_digit - Write a number using a buffer
 * @index: Index at which the number starts on the buffer
 * @buffer_output: Buffer array
 * @format_flags: handles active flags
 * @width: width
 * @precision: specifies precision
 * @len: length
 * @pdn: Padding character
 * @ex_ch: Extra character
 *
 * Return: number of printed characters
 */

int write_digit(int index, char buffer_output[], int format_flags, int width,
		int precision, int len, char pdn, char ex_ch)
{
	int x, pdn_s = 1;

	if (precision == 0 && index == BUFFER_SIZE - 2 &&
			buffer_output[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer_output[index] == '0')
		buffer_output[index] = pdn = ' ';
	if (precision > 0 && precision < len)
		pdn = ' ';
	while (precision > len)
		buffer_output[--index] = '0', len++;
	if (ex_ch != 0)
		len++;
	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			buffer_output[x] = pdn;
		buffer_output[x] = '\0';
		if (format_flags & FLAG_MINUS && pdn == ' ')
		{
			if (ex_ch)
				buffer_output[--index] = ex_ch;
			return (write(1, &buffer_output[index], len)
					+ write(1, &buffer_output[1], x - 1));
		} else if (!(format_flags & FLAG_MINUS) && pdn == ' ')
		{
			if (ex_ch)
				buffer_output[--index] = ex_ch;
			return (write(1, &buffer_output[1], x - 1)
					+ write(1, &buffer_output[index], len));
		} else if (!(format_flags & FLAG_MINUS) && pdn == '0')
		{
			if (ex_ch)
				buffer_output[--pdn_s] = ex_ch;
			return (write(1, &buffer_output[pdn_s], x - pdn_s) +
				write(1, &buffer_output[index], len - (1 - pdn_s)));	}
	}
	if (ex_ch)
		buffer_output[--index] = ex_ch;
	return (write(1, &buffer_output[index], len));
}

/**Write unsigned**/
/**
 * unsigned_write - writes an unsigned number
 * @is_negative: checks whether a number is negative
 * @index: Index at which the number starts in the buffer
 * @buffer_output: Array of chararacters
 * @format_flags: Flags specifier
 * @width: Width specifiers
 * @precision: Precision specifiers
 * @length: length specifiers
 *
 * Return: nNumber of written characters
 */

int unsigned_write(int is_negative, int index, char buffer_output[],
		int format_flags, int width, int precision, int length)
{
	int len = BUFFER_SIZE - index - 1, x = 0;
	char pdn = ' ';

	UNUSED(is_negative);
	UNUSED(length);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer_output[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pdn = ' ';

	while (precision > len)
	{
		buffer_output[--index] = '0';
		len++;
	}
	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		pdn = '0';

	if (width > len)
	{
		for (x = 0; x < width - len; x++)
			buffer_output[x] = pdn;
		buffer_output[x] = '\0';
		if (format_flags & FLAG_MINUS)
		{
			return (write(1, &buffer_output[index], len)
					+ write(1, &buffer_output[0], x));
		}
		else
		{
			return (write(1, &buffer_output[0], x)
					+ write(1, &buffer_output[index], len));
		}
	}
	return (write(1, &buffer_output[index], len));
}
/**Write pointer**/
/**
 * write_ptr - writes a memory address
 * @index: Index at which the number starts on the buffer
 * @buffer_output: Buffer array
 * @format_flags: handles active flags
 * @width: width specifiers
 * @precision: specifies precision
 * @len: length of number
 * @pdn: Padding character
 * @ex_ch: Extra character
 * @pdn_s: Starting index for padding
 * Return: number of printed characters
 */
int write_ptr(char buffer_output[], int index, int len,
	int width, int format_flags, char pdn, char ex_ch, int pdn_s)
{
	int x;

	if (width > len)
	{
		for (x = 3; x < width - len + 3; x++)
			buffer_output[x] = pdn;
		buffer_output[x] = '\0';
		if (format_flags & FLAG_MINUS && pdn == ' ')
		{
			buffer_output[--index] = 'x';
			buffer_output[--index] = '0';
			if (ex_ch)
				buffer_output[--index] = ex_ch;
			return (write(1, &buffer_output[index], len)
					+ write(1, &buffer_output[3], x - 3));
		}
		else if (!(format_flags & FLAG_MINUS) && pdn == ' ')
		{
			buffer_output[--index] = 'x';
			buffer_output[--index] = '0';
			if (ex_ch)
				buffer_output[--index] = ex_ch;
			return (write(1, &buffer_output[3], x - 3)
					+ write(1, &buffer_output[index], len));
		}
		else if (!(format_flags & FLAG_MINUS) && pdn == '0')
		{
			if (ex_ch)
				buffer_output[--pdn_s] = ex_ch;
			buffer_output[1] = '0';
			buffer_output[2] = 'x';
			return (write(1, &buffer_output[pdn_s], x - pdn_s) + write
					(1, &buffer_output[index], len - (1 - pdn_s) - 2));
		}
	}
	buffer_output[--index] = 'x';
	buffer_output[--index] = '0';
	if (ex_ch)
		buffer_output[--index] = ex_ch;
	return (write(1, &buffer_output[index], BUFFER_SIZE - index - 1));
}
