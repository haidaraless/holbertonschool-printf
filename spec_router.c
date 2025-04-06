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
char modifier = '\0';
unsigned int u;
unsigned long ul;
long n;

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

/* Parse length modifier */
if (*spec == 'l' || *spec == 'h')
{
modifier = *spec;
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
if (modifier == 'l')
n = va_arg(args, long);
else if (modifier == 'h')
n = (short)va_arg(args, int);
else
n = va_arg(args, int);
return (print_signed(n, flags));
}
if (*spec == 'p')
return (print_pointer(va_arg(args, void *)));
if (*spec == 'b')
unsigned int num = va_arg(args, unsigned int);
return (print_binary(num));
if (*spec == 'u')
{
if (modifier == 'l')
ul = va_arg(args, unsigned long);
else if (modifier == 'h')
u = (unsigned short)va_arg(args, int);
else
u = va_arg(args, unsigned int);
return (print_unsigned(modifier == 'l' ? ul : u));
}
if (*spec == 'x')
{
if (modifier == 'l')
ul = va_arg(args, unsigned long);
else if (modifier == 'h')
u = (unsigned short)va_arg(args, int);
else
u = va_arg(args, unsigned int);
return (print_hex(modifier == 'l' ? ul : u, 0, flags));
}
if (*spec == 'X')
{
if (modifier == 'l')
ul = va_arg(args, unsigned long);
else if (modifier == 'h')
u = (unsigned short)va_arg(args, int);
else
u = va_arg(args, unsigned int);
return (print_hex(modifier == 'l' ? ul : u, 1, flags));
}
if (*spec == 'o')
{
if (modifier == 'l')
ul = va_arg(args, unsigned long);
else if (modifier == 'h')
u = (unsigned short)va_arg(args, int);
else
u = va_arg(args, unsigned int);
return (print_octal(modifier == 'l' ? ul : u, flags));
}
write(1, "%", 1);
return (write(1, spec, 1) + 1);
}
