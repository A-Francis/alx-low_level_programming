#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to the binary string.
 * Return: The converted number, or 0 if there is an invalid character
 *         in the string or if b is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = '0';
	int i = '0'; /* Declare and initialize the loop variable */

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
	result = 2 * result + (b[i] - '0');
	}

	return (result);
}
