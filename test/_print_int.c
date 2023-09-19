#include "main.h"

/**
 * _printf_int - integers
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @d: int to print
 * Return: Number of characters
 */
int _printf_int(char *buffer, char *buf_ptr, int d)
{
	int len = 0, i, temp = d, sign = 0;
	char *str;

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
	{
		str[i] = d % 10 + '0';
		d /= 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		flush_buffer(buffer, buf_ptr);
		*buf_ptr = str[i];
		buf_ptr++;
	}
	free(str);
	return (len + sign);
}
