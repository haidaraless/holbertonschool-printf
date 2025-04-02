#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Handles format specifiers
 * @format: Pointer to current specifier
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_specifier(const char *format, va_list args)
{
char *s, buffer[12];
int count = 0, i, n, neg;

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
{
n = va_arg(args, int), neg = 0;
if (n == 0)
return (write(1, "0", 1));
if (n < 0)
neg = 1, n = -n;
for (i = 0; n; i++, n /= 10)
buffer[i] = (n % 10) + '0';
if (neg)
buffer[i++] = '-';
while (i--)
count += write(1, &buffer[i], 1);
return (count);
}
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
count += write(1, format, 1);
format++;
}
va_end(args);
return (count);
}
