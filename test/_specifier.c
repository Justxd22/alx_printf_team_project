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
	unsigned int octal[15];
	int i = 0, j, len;
	char *str;

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

        for (i = len; i >= 0 ; i--)
                _putchar(str[i]);

        free(str);
        return (len);

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
