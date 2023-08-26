#include "main.h"

/**
 * modify_size - Modifies a number to specified size
 * @n: number to be modified
 * @length: desired size specifier
 *
 * Return: modified number
 */

/***FOR PRINT INT**/

long int modify_size(long int n, int length)
{
	if (length == L_LONG)
		return (n);
	else if (length == L_SHORT)
		return ((short)n);
	return ((int)n);
}

/**
 * size_convert - converts number to specified size
 * @n: number to be converted
 * @length: desired size specified
 *
 * Return: converted number with size specified
 */

/****FOR PRINT HEXA UPPER OR LOWER****/

long int size_convert(unsigned long int n, int length)
{
	if (length == L_LONG)
		return (n);
	else if (length == L_SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}

/**
 * j_printable - checks if a character is printable
 * @ch: The character to be checked
 *
 * Return: 1 if @ch is printable, 0 otherwise
 */

/********FOR NON-PRINTABLE*****/

int j_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}

/**
 * is_digit - checks if a character is a digit
 * @ch: character to be checked
 *
 * Return: 1 if @ch is a digit, 0 otherwise
 */

/******FOR HANDLE WIDTH*****/

int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

/**
 * append_hexa - Appends ASCII in hexadecimal format to a buffer
 * @ascii: ASCII  value to be converted
 * @buffer_output: The buffer to store the output
 * @j: index at which to start appending in the buffer
 *
 * Return: The number of characters appended (always 3)
 */

/********for non printable hexa***************/

int append_hexa(char ascii, char buffer_output[], int j)
{
	char mapping[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;
	buffer_output[j++] = 'x';
	buffer_output[j++] = '\\';

	buffer_output[j++] = mapping[ascii / 16];
	buffer_output[j] = mapping[ascii % 16];

	return (3);
}
