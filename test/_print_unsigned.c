#include "main.h"

/**
 * _printf_unsigned_bin - print unsigned int argument as binary
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @b: unsigned int to print
 * Return: Number of characters printed
 */
int _printf_unsigned_bin(char *buffer, char *buffer_ptr, unsigned int b)
{
	int i = 32, j, len = 0;
	char *bin_string = malloc(33 * sizeof(char));

	flush_buffer(buffer, buffer_ptr);
	if (bin_string == NULL)
		return (0);

	if (b == 0)
	{
		*buffer_ptr = '0';
		buffer_ptr++;
		free(bin_string);
		return (1);
	}

	while (b > 0)
	{
		bin_string[i--] = (b % 2) + '0';
		b /= 2;
	}

	for (j = i + 1; j < 33; j++)
	{
		flush_buffer(buffer, buffer_ptr);
		*buffer_ptr = bin_string[j];
		buffer_ptr++, len++;
	}
	free(bin_string);
	return (len);
}
