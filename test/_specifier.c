#include "main.h"

/**
 * _printf_unsigned_int - handles %u specifier
 * @u: unsigned int to print
 * Return: length of int
 */

int _printf_unsigned_int(unsigned int u)
{
	unsigned int buffer = u;
	int len = 0, i;
	char *str;

	while (buffer)
	{
		buffer /= 10;
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
		_putchar(str[i]);

	free(str);
	return (len);
}

/**
 * _printf_octal - handles %o specifier
 * @o: unsigned to octal then print
 * Return: size of octal
 */

int _printf_octal(unsigned int o)
{
	unsigned int octal = 0;
	unsigned long int i = 1;

	while (o != 0)
	{
		octal = octal + ((o % 8) * i);
		o = o / 8;
		i *= 10;
		printf("%u / %u / %u\n", octal, o, i);
	}

	return (_printf_unsigned_int(octal));
}

/**
 * _printf_hexa_small - handles %x specifier
 * @x: unsigned to hexa small
 * Return: size of hexa
 */

/**
 * _printf_hexa_cap - handles %X specifier
 * @X: unsigned to hexa cap
 * Return: size of hexa
 */
