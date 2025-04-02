#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* process_format - Handles the format specifiers
* @format: The format specifier
* @args: List of arguments
*
* Return: Number of characters printed
*/
int process_format(const char *format, va_list args)
{
int count = 0;

if (*format == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
count += write(1, str, 1);
str++;
}
}
else if (*format == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
count += write(1, format, 1);
}
return (count);
}

/**
* _printf - Produces output according to a specific format
* @format: A string containing the format specifiers and text
*
* Return: Total number of characters printed
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
if (*format == '%')
{
format++;
if (*format == '\0')
return (-1);
count += process_format(format, args);
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
