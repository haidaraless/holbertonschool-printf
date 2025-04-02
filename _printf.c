#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf implementation
 * @format: Format string
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
count += route_specifier(format, args);
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
