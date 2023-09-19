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
