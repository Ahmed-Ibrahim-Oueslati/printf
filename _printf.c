#include "main.h"
#include <stdarg.h>
/**
* _printf - Prints arguments based on a format string.
* @format: The format string.
* @...: The arguments to print.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, nb = 0;
char *str;
if (!format)
return ((-1));
va_start(ap, format);
while (format[i])
{
if (format[i] == '%' && format[i + 1])
{
i++;
switch (format[i])
{
case 's':
str = va_arg(ap, char *);
if (!str)
str = "(nil)";
while (*str)
nb += _putchar(*str++);
break;
case 'c':
nb += _putchar(va_arg(ap, int));
break;
case '%':
nb += _putchar('%');
break;
default:
nb += _putchar('%');
nb += _putchar(format[i]);
break;
}
}
else
{
	nb += _putchar(format[i]);
}
i++;
}
va_end(ap);
return ((nb));
}
