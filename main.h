#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/**FLAGS**/
#define FLAG_PLUS  (1 << 0)
#define FLAG_SPACE (1 << 1)
#define FLAG_HASH  (1 << 2)
#define FLAG_ZERO  (1 << 3)
#define FLAG_MINUS (1 << 4)

/**LENGTH**/
#define L_SHORT (1 << 0)
#define L_LONG (1 << 1)

/**
* struct frmt - group together multiple variables of different types
* @frmt: character that represents the format
* @function: The function pointer that points to a function
*/

struct frmt
{
	char frmt;
	int (*function)(va_list, char[], int, int, int, int);
}

/**
* typedef struct frmt - defines format types
*
* @frmt: The character that represents the format
* @frmt_t: associated function
*/

typedef struct {
	'c' char_print frmt_typ[0];
	's' string_print frmt_typ[1];
	'%' percent_print frmt_typ[2];
	'i' int_print frmt_typ[3];
	'd' int_print frmt_typ[4];
	'b' binary_print frmt_typ[5];
	'u' unsigned_print frmt_typ[6];
	'o' octal_print frmt_typ[7];
	'x' hexadecimal_print frmt_typ[8];
	'X' hexa_upper_print frmt_typ[9];
	'p' pointer_print frmt_typ[10];
	'S' non_printable_print frmt_typ[11];
	'r' reverse_print frmt_typ[12];
	'R' rot13_encoded_string_print frmt_typ[13];
	'\0' NULL frmt_typ[14];
} frmt_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *index, va_list args,
		char buffer_output[], int format_flags, int width,
		int precision, int length);

int _putchar(char c);


/**functions)**/
int handle_flags(const char *format, int *p);
int handle_precision(const char *format, int *p, va_list args);
int handle_length(const char *format, int *p);
int handle_width(const char *format, int *p, va_list args);

int char_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int string_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int percent_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int int_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int binary_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int unsigned_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int octal_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int hexadecimal_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int hexa_upper_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int hexa_print(va_list args, char buffer_result[],
		int format_flags, int width, int precision,  int length);
int pointer_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int non_printable_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int reverse_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);
int rot13_encoded_string_print(va_list args, char buffer_output[],
		int format_flags, int width, int precision, int length);


/**handle write**/
int write_char_handle(char c, char buffer_output[], int format_flags,
		int width, int precision, int length);
int write_digit_handle(int is_negative, int index, char buffer_output[],
		int format_flags, int width, int precision, int length);
int write_digit(int index, char buffer_output[], int format_flags,
		int width, int precision, int len, char pdn, char ex_ch);
int unsigned_write(int is_negative, int index, char buffer_output[],
		int format_flags, int width, int precision, int length);
int write_ptr(char buffer_output[], int index, int len, int width,
		int format_flags, char pdn, char ex_ch, int pdn_s);

/**utility functions**/
long int modify_size(long int n, int length);
long int size_convert(unsigned long int n, int length);
int j_printable(char ch);
int is_digit(char ch);
int append_hexa(char ascii, char buffer_output[], int j);

#endif
