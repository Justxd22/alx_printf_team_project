#include "main.h"

/**
 * flush_buffer - helper func to check if buffer is full => if so free it
 * @buffer: buffer to check
 * @buffer_ptr: pointer to keep track of buffer position
 * No Return
 */
void flush_buffer(char *buffer, char *buffer_ptr)
{
	if (buffer_ptr - buffer >= 1024)
	{
		write(1, buffer, buffer_ptr - buffer);
		buffer_ptr = buffer;
	}
}
