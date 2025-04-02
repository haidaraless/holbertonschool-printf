#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
unsigned int num;
char buffer[12];
int i = 0, count = 0;

if (n < 0)
{
count += write(1, "-", 1);
num = -((unsigned int)n);
}
else
{
num = n;
}

if (num == 0)
return (write(1, "0", 1));

while (num)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}
while (i--)
count += write(1, &buffer[i], 1);

return (count);
}

/**
 * handle_specifier - Handles format specifiers
 * @format: The format specifier
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_specifier(const char *format, va_list args)
{
char *s;
int count = 0;

if (*format == 'c')
return (write(1, &(char){va_arg(args, int)}, 1));
else if (*format == 's')
{
s = va_arg(args, char *);
if (!s)
s = "(null)";
while (*s)
count += write(1, s++, 1);
return (count);
}
else if (*format == 'd' || *format == 'i')
return (print_number(va_arg(args, int)));
else if (*format == '%')
return (write(1, "%", 1));

return (write(1, "%", 1) + write(1, format, 1));
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%' && *(format + 1))
{
format++;
count += handle_specifier(format, args);
}
else
{
count += write(1, format, 1);
}
format++;
}

va_end(args);
return (count);
}
