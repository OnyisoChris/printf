#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define INT_BUF_SIZE 1024

int _printf(const char *format, ...);
static void print_int(int num);

#endif
