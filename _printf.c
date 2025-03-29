#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a specific format
 * @format: A string containing the format specifiers and text
 *
 * Description:
 * This function processes the format string and calls the appropriate
 * handler functions based on the format specifiers.
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;

if (!format)
return (-1);

va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
if (*ptr == '\0')
return (-1);

if (*ptr == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*ptr == 's')
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
else if (*ptr == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
count += write(1, ptr, 1);
}
}
else
{
count += write(1, ptr, 1);
}
}

va_end(args);
return (count);
}
