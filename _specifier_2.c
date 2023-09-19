#include "main.h"

/**
 * _printf_string_special - handles %S specifier
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * @S: string to be handled
 * Return: length of string
 */
int _printf_string_special(char *buffer, char *buffer_ptr, const char *S)
{
	int i = 0, j, len = 0, buff = 0, dec;
	char *literal = "\\x", str[2];

	if (S == NULL)
		return (0);

	flush_buffer(buffer, buffer_ptr);
	while (S[i] != '\0')
	{
		if ((S[i] > 0 && S[i] < 32) || S[i] >= 127)
		{
			for (j = 0; literal[j] != '\0'; j++)
			{
				flush_buffer(buffer, buffer_ptr);
				*buffer_ptr = literal[j], buffer_ptr++;
			}
			len += 2, dec = S[i];
			for (j = 0; j < 2; j++)
			{
				buff = dec % 16;
				if (buff < 10)
					buff += '0';
				else
					buff += ('0' + 7);
				str[j] = buff, dec /= 16;
			}
			while (j >= 0)
			{
				--j, flush_buffer(buffer, buffer_ptr);
				*buffer_ptr = str[j], buffer_ptr++;
			}
			len += 3, i++;
		}
		else
		{
			flush_buffer(buffer, buffer_ptr);
			*buffer_ptr = S[i], buffer_ptr++, len++, i++;
		}
	}
	return (len);
}

/**
 * _printf_pointer - helper function turn pointer to hex string
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @ptr: pointer to print
 * Return: Hexadecimal address
 */
int _printf_pointer(char *buffer, char *buf_ptr, void *ptr)
{
	const char hexDigits[] = "0123456789abcdef";
	unsigned long int value = (unsigned long int)ptr, temp;
	int i = 0, hex, len = 0, j;
	char *str;

	flush_buffer(buffer, buf_ptr);
	temp = value;
	if (ptr == NULL)
		return (0);
	while (temp != 0)
	{
		temp /= 16;
		len++;
	}

	str = (char *)malloc((len + 3) * sizeof(char));
	if (str == NULL)
		return (0);
	str[i++] = '0';
	str[i++] = 'x';
	while (value != 0)
	{
		hex = value % 16;
		str[len + 3 - i] = hexDigits[hex];
		i++;
		value /= 16;
	}
	str[i] = '\0';

	for (j = 0; j < len + 3; j++)
	{
		flush_buffer(buffer, buf_ptr);
		*buf_ptr = str[j];
		buf_ptr++;
	}
	free(str);
	return (len + 3);
}
