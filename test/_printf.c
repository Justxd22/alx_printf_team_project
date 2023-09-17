#include "main.h"
#include <stdio.h>

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

	if (str == NULL)
		return (0);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (len);
}

/**
 * _printf_ukn - print unknown characters
 * @c: character to print
 * Return: Number of characters
 */
int _printf_ukn(char c)
{
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf_int - integers
 * @d: int to print
 * Return: Number of characters
 */
int _printf_int(int d)
{
	int len = 0, i, temp = d, sign = 0;
	char *str;

	if (d == 0)
	{
		_putchar('0');
		return (1);
	}

	if (d < 0)
	{
		_putchar('-');
		sign++;
		d = -d;
	}

	while (temp)
	{
		temp /= 10;
		len++;
	}

	str = (char *)malloc((len) * sizeof(char));
	if (str == NULL)
		return (0);

	for (i = 0; i < len; i++)
	{
		str[i] = d % 10 + '0';
		d /= 10;
	}

	for (i = len - 1; i >= 0; i--)
		_putchar(str[i]);

	free(str);
	return (len + sign);
}

/**
 * _printf - Custom printf function implementation.
 * @format: Format string containing conversion specifiers *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
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
				case 'i':
					count += _printf_int(va_arg(vars, int));
					break;
				case 'd':
					count += _printf_int(va_arg(vars, int));
					break;
				case '%':
					count += _printf_char('%');
					break;
				default:
					count += _printf_ukn(*format);
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
