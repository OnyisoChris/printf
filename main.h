#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**FLAGS**/
#define FLAG_PLUS  (1 << 0)  // Flag for '+'
#define FLAG_SPACE (1 << 1)  // Flag for 'space'
#define FLAG_HASH  (1 << 2)  // Flag for '#'
#define FLAG_ZERO  (1 << 3)  // Flag for '0'
#define FLAG_MINUS (1 << 4)  // Flag for '-'

/**Sizes**/
#define L_SHORT (1 << 0)
#define L_LONG (1 << 1)

/**functions)**/
int handle_flags(const char *format, int *p)
int handle_precision(const char *format, int *p, va_list list)
int handle_length(const char *format, int *p)
int handle_width(const char *format, int *p, va_list list)

int char_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)
int string_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)
int percent_print(va_list args, char buffer_output[], int format_flags, int width, int precision, int length)

int _printf(const char *format, ...);
int _putchar(char c);

#endif
