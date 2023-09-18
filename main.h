#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
void flush_buffer(char *buffer, char *buffer_ptr);
int _printf_unsigned_bin(char *buffer, char *buffer_ptr, unsigned int b);
int _printf_int(char *buffer, char *buf_ptr, int d);
int _printf(const char *format, ...);

#endif
