#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* specifier - Routes to the correct handler
* @spec: Format specifier
* @args: va_list
* Return: Printed characters
*/
int specifier(const char *spec, va_list args)
{
	if (*spec == 'c')
		return (print_char(args));
	if (*spec == 's')
		return (print_string(args));
	if (*spec == '%')
		return (print_percent());
	if (*spec == 'd' || *spec == 'i')
	{
		signed int n = va_arg(args, signed int);

		return (print_signed(n));
	}
	if (*spec == 'u')
	{
		unsigned int n = va_arg(args, unsigned int);

		return (print_unsigned(n));
	}
	if (*spec == 'p')
	{
		void *ptr = va_arg(args, void *);

		return (print_pointer(ptr));
	}
	if (*spec == 'x')
	{
		unsigned int n = va_arg(args, unsigned int);

		return (print_hex(n, 0));
	}
	if (*spec == 'X')
	{
		unsigned int n = va_arg(args, unsigned int);

		return (print_hex(n, 1));
	}
	if (*spec == 'o')
	{
		unsigned int n = va_arg(args, unsigned int);

		return (print_octal(n));
	}
	write(1, "%", 1);
	return (write(1, spec, 1) + 1);
}
