#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int _putchar(char c);
int _printf_unsigned(unsigned int b);
int _printf_unsigned_int(unsigned int u);
int _printf_octal(unsigned int o);
int _printf_hexa_small(unsigned int x);
int _printf_hexa_cap(unsigned int X);
int _printf_string_special(const char *S);
int _printf(const char *format, ...);

#endif
