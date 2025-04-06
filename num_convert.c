#include <unistd.h>
#include "main.h"

/**
 * print_signed - Prints a signed number
 * @n: The number to print
 * @flags: Struct containing format flags
 * Return: Number of characters printed
 */
int print_signed(long n, flags_t flags)
{
char temp[20];
int idx = 0, count = 0;
unsigned long abs_n;

if (n < 0)
{
count += write(1, "-", 1);
abs_n = -n;
}
else
{
abs_n = n;
if (flags.plus)
count += write(1, "+", 1);
else if (flags.space)
count += write(1, " ", 1);
}

if (abs_n == 0)
return (count + write(1, "0", 1));

while (abs_n)
{
temp[idx++] = (abs_n % 10) + '0';
abs_n /= 10;
}
while (idx--)
count += write(1, &temp[idx], 1);

return (count);
}

/**
 * print_unsigned - Prints an unsigned number
 * @n: The number to print (supports unsigned long)
 * Return: Number of characters printed
 */
int print_unsigned(unsigned long n)
{
char temp[20];
int idx = 0, count = 0;

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

/**
 * print_short_signed - Prints a signed short number
 * @n: The number to print
 * @flags: Struct containing format flags
 * Return: Number of characters printed
 */
int print_short_signed(short n, flags_t flags)
{
return (print_signed((long)n, flags));
}

/**
 * print_long_signed - Prints a signed long number
 * @n: The number to print
 * @flags: Struct containing format flags
 * Return: Number of characters printed
 */
int print_long_signed(long n, flags_t flags)
{
return (print_signed(n, flags));
}

/**
 * print_ushort - Prints an unsigned short number
 * @n: The number to print
 * Return: Number of characters printed
 */
int print_ushort(unsigned short n)
{
return (print_unsigned((unsigned long)n));
}

/**
 * print_ulong - Prints an unsigned long number
 * @n: The number to print
 * Return: Number of characters printed
 */
int print_ulong(unsigned long n)
{
return (print_unsigned(n));
}
