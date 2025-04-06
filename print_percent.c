#include "main.h"
#include <unistd.h>

/**
* print_percent - Handles %% specifier
* Return: Printed characters
*/
int print_percent(void)
{
return (write(1, "%", 1));
}
