#include "main.h"

int main(void)
{
int len = _printf("Hello %s, your grade is %c and %% good!\n", "Alice", 'A');
_printf("Printed %d characters.\n", len);
return 0;
}
