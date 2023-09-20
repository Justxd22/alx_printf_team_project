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
	int i = 0, len = 0, temp;

	if (S == NULL)
		return (0);

	flush_buffer(buffer, buffer_ptr);
	while (S[i] != '\0')
	{
		if (S[i] < 32 || S[i] >= 127)
		{
			flush_buffer(buffer, buffer_ptr);
			*buffer_ptr = '\\';
			buffer_ptr++;
			*buffer_ptr = 'x';
			buffer_ptr++;
			len += 2;
			temp = _printf_hexa_cap(buffer, buffer_ptr, (unsigned int)S[i]);
			len += temp, buffer_ptr += temp;
		}
		else
		{
			flush_buffer(buffer, buffer_ptr);
			*buffer_ptr = S[i], buffer_ptr++, len++;
		}
		i++;
	}
	return (len);
}

/**
 * _printf_reverse - print string in reverse?
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * @c: character to print
 * Return: Number of characters
 */
int _printf_reverse(char *buffer, char *buf_ptr, const char *c)
{
	int i, len;

	flush_buffer(buffer, buf_ptr);
	if (c == NULL)
		return (0);

	len = strlen(c);
	for (i = len - 1; i >= 0; i--)
	{
		flush_buffer(buffer, buf_ptr);
		*buf_ptr = c[i];
		buf_ptr++;
	}
	return (len);
}



/**
 * _printf_rot13 - encode string to rot13
 * @c: string to rot13
 * @buffer: buffer to check
 * @buf_ptr: pointer to keep track of buffer position
 * Return: Number of characters
 */
int _printf_rot13(char *buffer, char *buf_ptr, const char *c)
{
	char rot[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
ss[52]  = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
	int x = 0, z = 0, len;
	char encoded;

	flush_buffer(buffer, buf_ptr);
	if (c == NULL)
		return (0);

	len = strlen(c);
	for (x = 0; x < len; x++)
	{
		encoded = c[x];
		for (z = 0; z < 52; z++)
		{
			if (c[x] == rot[z])
			{
				encoded = ss[z];
				z = 52;
			}
		}

		flush_buffer(buffer, buf_ptr);
		*buf_ptr = encoded;
		buf_ptr++;
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
