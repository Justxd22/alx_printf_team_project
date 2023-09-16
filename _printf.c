#include "main.h"

/**
 * _printf - Custom printf function implementation.
 * @format: Format string containing conversion specifiers *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	const char *str;
	va_list vars;

	va_start(vars, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _printf_char(va_arg(vars, int));
					break;
				case 's':
					count += _printf_string(va_arg(vars, const char *));
					break;
				case '%':
					count += _printf_char('%');
					break;
				default:
					break;
			}
		}
		else
		{
			count += _printf_char(*format);
		}
		format++;
	}
	va_end(vars);
	return (count);
}

/**
 * _printf_char - helper func to print char
 * @c: char to print
 * Return: Number of characters
 */
int _printf_char(int c)
{
	_putchar(c);
	return (1);
}

/**
 * _printf_string - helper func to print strings
 * @str: string to print
 * Return: Number of characters
 */
int _printf_string(const char *str)
{
	int i, len;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (len);
}
