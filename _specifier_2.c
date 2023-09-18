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
				flush_buffer(buffer, buffer_ptr);
				*buffer_ptr = str[j], buffer_ptr++, j--;
			}
			len += 2, i++;
		}
		else
		{
			flush_buffer(buffer, buffer_ptr);
			*buffer_ptr = S[i], buffer_ptr++, len++, i++;
		}
	}
	return (len);
}
