#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * route_specifier - Routes to the correct printer
 * @spec: Format specifier
 * @args: Arguments
 *
 * Return: Printed characters
 */
int route_specifier(const char *spec, va_list args)
{
if (*spec == 'c')
return (write(1, &(char){va_arg(args, int)}, 1));
else if (*spec == 's')
{
char *str = va_arg(args, char *);
int count = 0;

if (!str)
str = "(null)";
while (*str)
count += write(1, str++, 1);
return (count);
}
else if (*spec == '%')
return (write(1, "%", 1));
else if (*spec == 'd' || *spec == 'i')
return (print_signed(va_arg(args, int)));
else if (*spec == 'u')
return (print_unsigned(va_arg(args, unsigned int)));
else if (*spec == 'x')
return (print_hex(va_arg(args, unsigned int), 0));
else if (*spec == 'X')
return (print_hex(va_arg(args, unsigned int), 1));
else if (*spec == 'o')
return (print_octal(va_arg(args, unsigned int)));

write(1, "%", 1);
return (write(1, spec, 1) + 1);
}
