#include "main.h"
#include <stdio.h>

/**
 * _printf_unsigned - print unsigned int argument as binary
 * @b: unsigned int to print
 * Return: Number of characters printed
 */
int _printf_unsigned(unsigned int b)
{
	int i = 32, j, len = 0;
	char *bin_string = malloc(33 * sizeof(char));

	if (bin_string == NULL)
		return (0);

	if (b == 0)
	{
		_putchar('0');
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
		_putchar(bin_string[j]);
		len++;
	}

	free(bin_string);
	return (len);
}
