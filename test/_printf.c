#include "main.h"
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, and '%%' for a literal '%'.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0;
char *str;
char c;
int found = 0;
if (!format)
return ((-1));
va_start(ap, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
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
case '%':
_putchar('%');
nb++;
found = 1;
break;
default:
break;
}
}
else
{
_putchar(format[i]);
nb++;
}
i++;
}
va_end(ap);
if (!found)
return ((0));
return ((nb));
}
