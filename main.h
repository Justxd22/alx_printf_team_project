#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * struct Res - for multi returns
 * @c: chars count
 * @modifier: used modifiers? 0/1
 *
 * Description: used for multi returns from functions
 */
struct Res
{
	int c;
	int modifier;
};

typedef struct Res Result;

int _print_nill(char *buffer, char *buffer_ptr);
void flush_buffer(char *buffer, char *buffer_ptr);
long int _swap_types(long int q, int type);
unsigned long int _swap_types_unsigned_int(unsigned long int q, int type);
int _printf_int(char *buffer, char *buf_ptr, va_list vars, int type);
int _printf_unsigned_bin(char *buffer, char *buffer_ptr, unsigned int b);
int _printf_unsigned_int(char *buffer, char *buffer_ptr,
va_list vars, int type);
int _printf_octal(char *buffer, char *buffer_ptr, va_list vars, int type);
int _printf_hexa_small(char *buffer, char *buffer_ptr, va_list vars, int type);
int _printf_hexa_cap(char *buffer, char *buffer_ptr, va_list vars, int type);
int _printf_hexa_cap_normal(char *buffer, char *buffer_ptr, unsigned int X);
int _printf_string_special(char *buffer, char *buffer_ptr, const char *S);
int _printf_reverse(char *buffer, char *buf_ptr, const char *c);
int _printf_rot13(char *buffer, char *buf_ptr, const char *c);
int _printf_pointer(char *buffer, char *buf_ptr, void *p);
int _printf_ukn(char *buffer, char *buf_ptr, char c);
int _printf_long_short(char *buffer, char *buf_ptr, char format,
va_list vars, int type);
Result _printf_detect_format_pt2(char *buffer, char *buf_ptr,
const char *format, va_list vars);
int _printf(const char *format, ...);

#endif
