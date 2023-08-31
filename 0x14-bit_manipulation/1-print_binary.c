#include "main.h"

/**
 * print_binary - prints binary equivalent to a decimal
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	int i, count = '0';
	unsigned long int main;

	for (i = 63; i >= 0; i--)
	{
		main = n >> i;

		if (main & 1)
		{
			putchar('1');
			count++;
		}
		else if (count)
			putchar('0');
	}
	if (!count)
		putchar('0');
}

