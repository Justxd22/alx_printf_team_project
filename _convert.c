#include "main.h"

/**
 * _swap_types - swap long/short/int
 * @q: int to swap
 * @type: type to use
 * Return: Number of characters
 */
long int _swap_types(long int q, int type)
{
	if (type == 1)
		return (q);
	else if (type == 2)
		return ((short)q);
	return ((int)q);
}

/**
 * _swap_types_unsigned_int - swap long/short/int
 * @q: int to swap
 * @type: type to use
 * Return: Number of characters
 */
unsigned long int _swap_types_unsigned_int(unsigned long int q, int type)
{
	if (type == 1)
		return (q);
	else if (type == 2)
		return ((unsigned short)q);
	return ((unsigned int)q);
}
