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
count += handle_char(args);
else if (*ptr == 's')
count += handle_string(args);
else if (*ptr == '%')
count += handle_percent();
else
count += write(1, "%", 1);
}
else
{
count += write(1, ptr, 1);
}
}

va_end(args);
return (count);
}

/**
 * handle_char - Handles the printing of a character
 * @args: The arguments list
 *
 * Description:
 * This function takes a character from the argument list and prints to stdout
 *
 * Return: Number of characters printed (1)
 */
int handle_char(va_list args)
{
char c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
 * handle_string - Handles the printing of a string
 * @args: The arguments list
 *
 * Description:
 * This function takes a string from the argument list and prints it to stdout.
 * If the string is NULL, it prints "(null)" instead.
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
return (write_string(str));
}

/**
 * write_string - Writes a string to stdout
 * @str: The string to be printed
 *
 * Description:
 * This function prints each character of the string one by one to stdout.
 *
 * Return: Total number of characters printed
 */
int write_string(char *str)
{
int count = 0;
while (*str)
{
count += write(1, str, 1);
str++;
}
return (count);
}

/**
 * handle_percent - Handles the printing of a percent sign
 *
 * Description:
 * This function simply prints the percent sign ("%") to stdout.
 *
 * Return: Number of characters printed (1)
 */
int handle_percent(void)
{
return (write(1, "%", 1));
}
