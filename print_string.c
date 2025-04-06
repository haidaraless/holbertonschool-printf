#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* print_string - Handles %s specifier
* @args: va_list
* Return: Printed characters
*/
int print_string(va_list args)
{
char *s = va_arg(args, char *);
int count = 0;

if (!s)
s = "(null)";
while (*s)
count += write(1, s++, 1);
return (count);
}
