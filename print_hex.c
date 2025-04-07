#include "main.h"
#include <unistd.h>

/**
* print_hex - Prints a number in hexadecimal
* @n: The number
* @upper: 1 for uppercase, 0 for lowercase
* Return: Characters printed
*/
int print_hex(unsigned int n, int upper)
{
	char temp[20];
	char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	int i = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n)
	{
		temp[i++] = digits[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &temp[i], 1);

	return (count);
}
