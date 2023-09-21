#include "main.h"


/**
 * _printf_detect_format_pt2 - helper
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @format: current char
 * @vars: vars
 * Return: Number of characters
 */
Result _printf_detect_format_pt2(char *buffer, char *buf_ptr,
const char *format, va_list vars)
{
	Result r;

	r.modifier = 0;
	switch (*format)
	{
		case 'x':
			r.c = _printf_hexa_small(buffer, buf_ptr, vars, 0);
			break;
		case 'X':
			r.c = _printf_hexa_cap(buffer, buf_ptr, vars, 0);
			break;
		case 'S':
			r.c = _printf_string_special(buffer, buf_ptr,
va_arg(vars, const char *));
			break;
		case 'p':
			r.c = _printf_pointer(buffer, buf_ptr, va_arg(vars, void *));
			break;
		case 'h':
		case 'l':
			format++, r.c = _printf_long_short(buffer, buf_ptr, *format, vars,
((*format == 'l') ? 1 : 0)), r.modifier = 1;
			break;
		default:
			r.c = _printf_ukn(buffer, buf_ptr, *format);
			break;
	}
	return (r);
}

/**
 * _printf_long_short - use long/short according to L/H specifier
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @format: next char
 * @vars: next var
 * @type: modifier type long/short
 * Return: Number of characters
 */
int _printf_long_short(char *buffer, char *buf_ptr, char format, va_list vars,
int type)
{
	switch (format)
	{
		case 'i':
		case 'd':
			return (_printf_int(buffer, buf_ptr, vars, type));
		case 'u':
			return (_printf_unsigned_int(buffer, buf_ptr, vars, type));
		case 'o':
			return (_printf_octal(buffer, buf_ptr, vars, type));
		case 'x':
			return (_printf_hexa_small(buffer, buf_ptr, vars, type));
		case 'X':
			return (_printf_hexa_cap(buffer, buf_ptr, vars, type));
		default:
			return (_printf_ukn(buffer, buf_ptr, format));

	}
}



/**
 * _printf_hexa_cap_normal - handles %X specifier (for normal cases)
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @X: unsigned to hexa cap
 * Return: size of hexa
 */
int _printf_hexa_cap_normal(char *buffer, char *buffer_ptr, unsigned int X)
{
	int i = 0, j, len = 0;
	unsigned int buf, count = X;
	char *str;

	flush_buffer(buffer, buffer_ptr);
	while (count != 0)
	{
		count /= 16;
		len++;
	}

	str = (char *)malloc((len + 1) * sizeof(char));
	while (X != 0)
	{
		buf = X % 16;

		if (buf < 10)
			buf += '0';
		else
			buf += ('0' + 7);

		str[i] = buf;
		i++;
		X /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = str[j];
		buffer_ptr++;
	}
	free(str);
	return (len);
}


/**
 * _print_nill - print nill for null entries
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * Return: Number of characters
 */
int _print_nill(char *buffer, char *buffer_ptr)
{
	char *n = "(nil)";
	int x;

	for (x = 0; n[x] != '\0'; x++)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = n[x];
		buffer_ptr++;
	}

	return (5);
}


/**
 * _print_null - print null for null entries
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * Return: Number of characters
 */
int _print_null(char *buffer, char *buffer_ptr)
{
	char *n = "(null)";
	int x;

	for (x = 0; n[x] != '\0'; x++)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = n[x];
		buffer_ptr++;
	}

	return (6);
}
