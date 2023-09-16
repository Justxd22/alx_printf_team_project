#include "main.h"
/**
 * _printf - Custom printf function implementation.
 * @format: Format string containing conversion specifiers *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count, i = 0;
	va_list vars;

	va_start(vars, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(vars, int);

					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *str = va_arg(vars, const char *);

					for(i = 0; i < strlen(str); i++)
					{
						_putchar(str[i]);
						count++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count++;
					break;
				}
				default:
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(vars);
	return (count);
}
