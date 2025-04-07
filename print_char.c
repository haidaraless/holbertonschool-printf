#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* print_char - Handles %c specifier
* @args: va_list
* Return: Printed characters
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
