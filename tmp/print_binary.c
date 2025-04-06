#include <stdio.h>
#include "main.h"

/* Function to convert an unsigned integer to binary and print it */
void print_binary(unsigned int num)
{
/* Find the highest bit set in num */
unsigned int mask = 1 << (sizeof(num) * 8 - 1);

/* Loop through each bit */
int started = 0;  /* To skip leading zeros */
size_t i;

for (i = 0; i < sizeof(num) * 8; ++i)
{
if (num & mask)
{
putchar('1');
started = 1;
}
else if (started)
putchar('0');
mask >>= 1;  /* Shift mask to the next bit */
}
if (!started)
putchar('0'); /* If no bits were printed (i.e., num is 0), print '0' */
}
