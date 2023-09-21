#include "main.h"

/**
 * _printf_char - helper func to print char
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @c: char to print
 * Return: Number of characters
 */
int _printf_char(char *buffer, char *buf_ptr, int c)
{
	flush_buffer(buffer, buf_ptr);
	*buf_ptr = c;
	buf_ptr++;
	return (1);
}

/**
 * _printf_string - helper func to print strings
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @str: string to print
 * Return: Number of characters
 */
int _printf_string(char *buffer, char *buf_ptr, const char *str)
{
	int i, len;

	flush_buffer(buffer, buf_ptr);
	if (str == NULL)
		return (_print_null(buffer, buf_ptr));

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		flush_buffer(buffer, buf_ptr);
		*buf_ptr = str[i];
		buf_ptr++;
	}
	return (len);
}

/**
 * _printf_ukn - print unknown characters
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @c: character to print
 * Return: Number of characters
 */
int _printf_ukn(char *buffer, char *buf_ptr, char c)
{
	flush_buffer(buffer, buf_ptr);
	*buf_ptr = '%';
	buf_ptr++;
	*buf_ptr = c;
	buf_ptr++;
	return (2);
}

/**
 * _printf_detect_format - helper
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @format: current char
 * @vars: vars
 * Return: Number of characters
 */
Result _printf_detect_format(char *buffer, char *buf_ptr,
const char *format, va_list vars)
{
	Result r;

	r.modifier = 0;
	switch (*format)
	{
		case 'c':
			r.c = _printf_char(buffer, buf_ptr, va_arg(vars, int));
			break;
		case 's':
			r.c = _printf_string(buffer, buf_ptr, va_arg(vars, const char *));
			break;
		case 'r':
			r.c = _printf_reverse(buffer, buf_ptr, va_arg(vars, const char *));
			break;
		case 'R':
			r.c = _printf_rot13(buffer, buf_ptr, va_arg(vars, const char *));
			break;
		case 'i':
		case 'd':
			r.c = _printf_int(buffer, buf_ptr, vars, 0);
			break;
		case 'b':
			r.c = _printf_unsigned_bin(buffer, buf_ptr, va_arg(vars,
unsigned int));
			break;
		case '%':
			r.c = _printf_char(buffer, buf_ptr, '%');
			break;
		case 'u':
			r.c = _printf_unsigned_int(buffer, buf_ptr, vars, 0);
			break;
		case 'o':
			r.c = _printf_octal(buffer, buf_ptr, vars, 0);
			break;
		default:
			return (_printf_detect_format_pt2(buffer, buf_ptr, format, vars));
	}
	return (r);
}


/**
 * _printf - Custom printf function implementation.
 * @format: Format string containing conversion specifiers *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	Result temp;
	char buffer[1024], *buf_ptr = buffer;
	va_list vars;

	va_start(vars, format);
	if (format == NULL)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			temp = _printf_detect_format(buffer, buf_ptr, format, vars);
			count += temp.c, buf_ptr += temp.c, format += temp.modifier;
		}
		else
			count += _printf_char(buffer, buf_ptr, *format), buf_ptr++;
		format++;
		flush_buffer(buffer, buf_ptr);
	}
	va_end(vars);
	(buf_ptr > buffer) ? write(1, buffer, buf_ptr - buffer) : 0;
	return (count);
}
