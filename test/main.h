#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _printf_unsigned_int(unsigned int u);
int _printf_octal(unsigned int o);

#endif
