#include "main.h"
#include <unistd.h> // Include for the write function
#include <stdarg.h> // Include for va_list, va_start, and va_arg

/**
 * _printf - print an output and write it to standard output
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1); // Use write instead of printf for characters
                    break;
                }
                case 's':
                {
                    const char *s = va_arg(args, const char *);
                    while (*s != '\0')
                    {
                        write(1, s, 1); // Use write for each character in the string
                        s++;
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        char minus = '-';
                        write(1, &minus, 1);
                        num = -num;
                    }
                    int num_digits = 0;
                    int temp = num;
                    do
                    {
                        temp /= 10;
                        num_digits++;
                    } while (temp > 0);

                    char num_str[num_digits];
                    for (int i = num_digits - 1; i >= 0; i--)
                    {
                        num_str[i] = (num % 10) + '0';
                        num /= 10;
                    }
                    write(1, num_str, num_digits);
                    break;
                }
                case '%':
                {
                    char percent = '%';
                    write(1, &percent, 1); // Use write for the percent sign
                    break;
                }
            }
        }
        else
        {
            write(1, format, 1); // Use write for regular characters
        }
        format++;
        count++;
    }
    va_end(args);
    return count;
}
