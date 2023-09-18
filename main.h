#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
void flush_buffer(char *buffer, char *buffer_ptr);
int _printf_int(char *buffer, char *buf_ptr, int d);
int _printf_unsigned_bin(char *buffer, char *buffer_ptr, unsigned int b);
int _printf_unsigned_int(char *buffer, char *buffer_ptr, unsigned int u);
int _printf_octal(char *buffer, char *buffer_ptr, unsigned int o);
int _printf_hexa_small(char *buffer, char *buffer_ptr, unsigned int x);
int _printf_hexa_cap(char *buffer, char *buffer_ptr, unsigned int X);
int _printf(const char *format, ...);

#endif
