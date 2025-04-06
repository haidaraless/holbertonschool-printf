#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

/**
 * print_hex - Prints a number in hexadecimal
 * @n: The number // [MODIFIED: type changed to unsigned long]
 * @upper: 1 for uppercase, 0 for lowercase
 * @flags: Struct containing format flags
 * Return: Characters printed
 */
int print_hex(unsigned long n, int upper, flags_t flags) // [MODIFIED: unsigned int -> unsigned long]
{
char temp[20];
char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
int i = 0, count = 0;

/* Add 0x or 0X prefix only if hash flag is set and number is not zero */
if (flags.hash && n != 0)
{
if (upper)
count += write(1, "0X", 2);
else
count += write(1, "0x", 2);
}

if (n == 0)
return (count + write(1, "0", 1));

while (n)
{
temp[i++] = digits[n % 16];
n /= 16;
}
while (i--)
count += write(1, &temp[i], 1);

return (count);
}

/**
 * print_octal - Prints a number in octal
 * @n: The number // [MODIFIED: type changed to unsigned long]
 * @flags: Struct containing format flags
 * Return: Characters printed
 */
int print_octal(unsigned long n, flags_t flags) // [MODIFIED: unsigned int -> unsigned long]
{
char temp[20];
int i = 0, count = 0;

/* Add '0' prefix only if flag is set and number isn't zero */
if (flags.hash && n != 0)
count += write(1, "0", 1);

if (n == 0)
return (count + write(1, "0", 1));

while (n)
{
temp[i++] = (n % 8) + '0';
n /= 8;
}
while (i--)
count += write(1, &temp[i], 1);

return (count);
}
