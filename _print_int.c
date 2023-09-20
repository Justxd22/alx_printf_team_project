#include "main.h"

/**
 * _printf_int - integers
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @vars: next var
 * @type: long/short/normal
 * Return: Number of characters
 *
 *
 * desc: you can't compare 0 with long/short diff types
 */
int _printf_int(char *buffer, char *buf_ptr, va_list vars, int type)
{
	long int d = va_arg(vars, long int), temp = d;
	int len = 0, i, sign = 0;
	char *str;

	d = _swap_types(d, type), temp = _swap_types(temp, type);

	flush_buffer(buffer, buf_ptr);
	if (d == 0)
	{
		*buf_ptr = '0';
		buf_ptr++;
		return (1);
	}

	if (d < 0)
	{
		*buf_ptr = '-';
		buf_ptr++, sign++, d = -d;
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
		str[i] = d % 10 + '0', d /= 10;

	for (i = len - 1; i >= 0; i--)
	{
		flush_buffer(buffer, buf_ptr);
		*buf_ptr = str[i];
		buf_ptr++;
	}
	free(str);
	return (len + sign);
}
