#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - Handles %c specifier
 * @args: va_list
 * Return: Printed characters
 */
int handle_char(va_list args)
{
char c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
 * handle_string - Handles %s specifier
 * @args: va_list
 * Return: Printed characters
 */
int handle_string(va_list args)
{
char *s = va_arg(args, char *);
int count = 0;

if (!s)
s = "(null)";
while (*s)
count += write(1, s++, 1);
return (count);
}

/**
 * handle_percent - Handles %% specifier
 * Return: Printed characters
 */
int handle_percent(void)
{
return (write(1, "%", 1));
}

/**
 * route_specifier - Routes to the correct handler
 * @spec: Format specifier
 * @args: va_list
 * Return: Printed characters
 */
int route_specifier(const char *spec, va_list args)
{
if (*spec == 'c')
return (handle_char(args));
else if (*spec == 's')
return (handle_string(args));
else if (*spec == '%')
return (handle_percent());
else if (*spec == 'd' || *spec == 'i')
{
int n = va_arg(args, int);
return (print_signed int(n));
}
else if (*spec == 'u')
{
int n = va_arg(args, int);
return (print_unsigned int((unsigned int)n));
}
else if (*spec == 'x')
{
int n = va_arg(args, int);
return (print_hex((unsigned int)n, 0));
}
else if (*spec == 'X')
{
int n = va_arg(args, int);
return (print_hex((unsigned int)n, 1));
}
else if (*spec == 'o')
{
int n = va_arg(args, int);
return (print_octal((unsigned int)n));
}
write(1, "%", 1);
return (write(1, spec, 1) + 1);
}
