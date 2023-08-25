include "main.h"

/**
 *
 *
 *
 *
 */

/***FOR PRINT INT**/

long int modify_size(long int n, int size)
{
	if(size == L_LONG)
		return (n);
	else if(size == L_SHORT)
		return ((short)n);
	return ((int)n);
}

/**
 *
 *
 *
 */

/****FOR PRINT HEXA UPPER OR LOWER****/

long int size_convert(unsigned long int n, int size)
{
	if (size == L_LONG)
		return (n);
	else id (size == L_SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}

/**
 *
 *
 *
 *
 */

/********FOR NON-PRINTABLE*****/

int j_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}

/**
 *
 *
 *
 *
 */

/******FOR HANDLE WIDTH*****/

int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

/**
 *
 *
 *
 *
 *
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

