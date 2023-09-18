#include "main.h"

/**
 * _printf_unsigned_int - handles %u specifier
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @u: unsigned int to print
 * Return: length of int
 */
int _printf_unsigned_int(char *buffer, char *buffer_ptr, unsigned int u)
{
	unsigned int buf = u;
	int len = 0, i;
	char *str;

	flush_buffer(buffer, buffer_ptr);
	while (buf)
	{
		buf /= 10;
		len++;
	}

	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);

	for (i = len - 1; i >= 0; i--)
	{
		str[i] = u % 10 + '0';
		u /= 10;
	}
	str[len] = '\0';

	for (i = 0; i < len; i++)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = str[i];
		buffer_ptr++;
	}
	free(str);
	return (len);
}

/**
 * _printf_octal - handles %o specifier
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @o: unsigned to octal then print
 * Return: size of octal
 */
int _printf_octal(char *buffer, char *buffer_ptr, unsigned int o)
{
	unsigned int octal[15];
	int i = 0, j, len;
	char *str;

	flush_buffer(buffer, buffer_ptr);
	while (o != 0)
	{
		octal[i] = (o % 8);
		o = o / 8;
		i++;
	}

	len = i;

	str = (char *)malloc((len + 1) * sizeof(char));

	if (str == NULL)
		return (0);

	for (j = i; j >= 0; j--)
	{
		str[j] = octal[j] + '0';
	}
	str[len] = '\0';

	for (i = len; i >= 0; i--)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = str[i];
		buffer_ptr++;
	}

	free(str);
	return (len);

}

/**
 * _printf_hexa_cap - handles %X specifier
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @X: unsigned to hexa cap
 * Return: size of hexa
 */
int _printf_hexa_cap(char *buffer, char *buffer_ptr, unsigned int X)
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

	return (len);
}

/**
 * _printf_hexa_small  - handles %x specifier
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @x: unsigned to hexa small
 * Return: size of hexa
 *
 * Description: we added 32 to the previous code to
 * print small letters instead
 */
int _printf_hexa_small(char *buffer, char *buffer_ptr, unsigned int x)
{
	int i = 0, j, len = 0;
	unsigned int buf, count = x;
	char *str;

	flush_buffer(buffer, buffer_ptr);
	while (count != 0)
	{
		count /= 16;
		len++;
	}

	str = (char *)malloc((len + 1) * sizeof(char));
	while (x != 0)
	{
		buf = x % 16;

		if (buf < 10)
			buf += '0';
		else
			buf += ('0' + 7 + 32);
		str[i] = buf;
		i++;
		x /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = str[j];
		buffer_ptr++;
	}

	return (len);
}
