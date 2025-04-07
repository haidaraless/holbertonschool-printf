#include "main.h"
#include <unistd.h>

/**
* print_unsigned - Prints an unsigned number
* @n: The number to print
* Return: Number of characters printed
*/
int print_unsigned(unsigned int n)
{
	char temp[20];
	unsigned int idx = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n)
	{
		temp[idx++] = (n % 10) + '0';
		n /= 10;
	}
	while (idx--)
		count += write(1, &temp[idx], 1);

	return (count);
}
