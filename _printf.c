#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string.
* @...: A variable number of arguments.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i, j, nb;
char *str;
char c;
int found = nb = 0;
if (!format)
return (-1);
va_start(ap, format);
while (format[i])
{
switch (format[i])
{
case '%':
c = va_arg(ap, int);
_putchar(c);
nb++;
found = 1;
break;
case 'c':
c = va_arg(ap, int);
_putchar(c);
nb++;
found = 1;
break;
case 's':
str = va_arg(ap, char *);
if (str == NULL)
str = "(nil)";
j = 0;
while (str[j] != '\0')
{
_putchar(str[j]);
nb++;
j++;
}
found = 1;
break;
default:
break;
}
i++;
}
va_end(ap);
if (!found)
return ((0));
return (nb);
}
