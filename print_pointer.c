#include <unistd.h>
#include <stdint.h>

/**
* print_pointer - prints a pointer address
* @p: the pointer to print
*
* Return: number of characters printed
*/
int print_pointer(void *p)
{
int count = 0;
uintptr_t addr = (uintptr_t)p;
char buffer[16]; /* Enough for 64-bit address */
int i = 0;
char hex_digits[] = "0123456789abcdef";

if (p == NULL)
{
write(1, "(nil)", 5);
return (5);
}

/* Print "0x" prefix */
write(1, "0x", 2);
count += 2;

/* Handle zero address */
if (addr == 0)
{
write(1, "0", 1);
return (count + 1);
}

/* Convert to hexadecimal */
while (addr != 0)
{
buffer[i++] = hex_digits[addr % 16];
addr /= 16;
}

/* Print in correct order */
while (i > 0)
{
write(1, &buffer[--i], 1);
count++;
}

return (count);
}
