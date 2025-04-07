#include "main.h"
#include <unistd.h>

/**
* print_octal - Prints a number in octal
* @n: The number
* Return: Characters printed
*/
int print_octal(unsigned int n)
{
	char temp[20];
	int i = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n)
	{
		temp[i++] = (n % 8) + '0';
		n /= 8;
	}
	while (i--)
	count += write(1, &temp[i], 1);

	return (count);
}
