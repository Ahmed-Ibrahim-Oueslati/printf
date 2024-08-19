#include "main.h"
/**
* _printf - Prints arguments based on a format string.
* @format: The format string.
* @...: The arguments to print.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0;
char *str;
if (!format)
return (((-1)));
va_start(ap, format);
while (format[i])
{
switch (format[i])
{
case 'c':
nb += _putchar(va_arg(ap, int));
break;
case 's':
str = va_arg(ap, char *);
if (!str)
str = "(nil)";
for (j = 0; str[j]; j++)
nb += _putchar(str[j]);
break;
case '%':
nb += _putchar('%');
break;
default:
nb += _putchar(format[i]);
break;
}
i++;
}
va_end(ap);
return (nb);
}
