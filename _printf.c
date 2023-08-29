#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

/**@num: integer to be computed **/

static void print_int(int num);

/**
 * _printf - Print formatted output
 * @format: format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':	{
						char c = (char)va_arg(args, int);

						write(1, &c, 1);
						count++;
						break;
						}
				case 's': {
						const char *s = va_arg(args, const char *);

				while (*s)
				{
					write(1, s, 1);
					s++;
					count++;
				}
				break;
					}
				case 'd':
				case 'i': {
						int num = va_arg(args, int);

						print_int(num);
						count += INT_BUF_SIZE;
						break;
						}
				case '%':	{
						char percent = '%';

						write(1, &percent, 1);
						count++;
						break;
						}
			}
		} else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * print_int - Print integer to standard output
 * @num: The integer to be printed
 *
 */
static void print_int(int num)
{
	char int_buffer[INT_BUF_SIZE];
	int buffer_index = INT_BUF_SIZE - 1;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		int_buffer[buffer_index] = (num % 10) + '0';
		num /= 10;
		buffer_index--;
	} while (num != 0);
	if (is_negative)
	{
		int_buffer[buffer_index] = '-';
		buffer_index--;
	}

	write(1, &int_buffer[buffer_index + 1], INT_BUF_SIZE - buffer_index - 1);
}
