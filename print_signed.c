#include "main.h"
#include <unistd.h>

/**
* print_signed - Prints a signed number
* @n: The number to print
* Return: Number of characters printed
*/
int print_signed(signed int n)
{
	char temp[20];
	int idx = 0, count = 0;
	signed long abs_n;

	if (n < 0)
	{
		count += write(1, "-", 1);
		abs_n = -n;
	}
	else
		abs_n = n;

	if (abs_n == 0)
		return (write(1, "0", 1));

	while (abs_n)
	{
		temp[idx++] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	while (idx--)
		count += write(1, &temp[idx], 1);

	return (count);
}
