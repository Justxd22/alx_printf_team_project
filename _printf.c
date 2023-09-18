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
		return (0);

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
int _printf_detect_format(char *buffer, char *buf_ptr,
const char *format, va_list vars)
{

	switch (*format)
	{
		case 'c':
			return (_printf_char(buffer, buf_ptr, va_arg(vars, int)));
		case 's':
			return (_printf_string(buffer, buf_ptr, va_arg(vars, const char *)));
		case 'i':
			return (_printf_int(buffer, buf_ptr, va_arg(vars, int)));
		case 'd':
			return (_printf_int(buffer, buf_ptr, va_arg(vars, int)));
		case 'b':
			return (_printf_unsigned_bin(buffer, buf_ptr, va_arg(vars, unsigned int)));
		case '%':
			return (_printf_char(buffer, buf_ptr, '%'));
		default:
			return (_printf_ukn(buffer, buf_ptr, *format));
	}

}



/**
 * _printf - Custom printf function implementation.
 * @format: Format string containing conversion specifiers *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0, temp = 0;
	char buffer[1024], *buf_ptr = buffer;
	va_list vars;

	va_start(vars, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			temp = _printf_detect_format(buffer, buf_ptr, format, vars);
			count += temp, buf_ptr += temp;
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
