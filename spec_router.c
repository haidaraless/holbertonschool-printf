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
flags_t flags = {0, 0, 0};

/* Parse flags if any */
while (*spec == '+' || *spec == ' ' || *spec == '#')
{
if (*spec == '+')
flags.plus = 1;
else if (*spec == ' ')
flags.space = 1;
else if (*spec == '#')
flags.hash = 1;
spec++;
}

if (*spec == 'c')
return (handle_char(args));
if (*spec == 's')
return (handle_string(args));
if (*spec == '%')
return (handle_percent());
if (*spec == 'd' || *spec == 'i')
{
long n = va_arg(args, long);
return (print_signed(n, flags));
}
if (*spec == 'p')
{
void *ptr = va_arg(args, void *);
return (print_pointer(ptr));
}
if (*spec == 'u')
{
unsigned int n = va_arg(args, unsigned int);
return (print_unsigned(n));
}
if (*spec == 'x')
{
unsigned int n = va_arg(args, unsigned int);
return (print_hex(n, 0, flags));
}
if (*spec == 'X')
{
unsigned int n = va_arg(args, unsigned int);
return (print_hex(n, 1, flags));
}
if (*spec == 'o')
{
unsigned int n = va_arg(args, unsigned int);
return (print_octal(n, flags));
}
write(1, "%", 1);
return (write(1, spec, 1) + 1);
}
