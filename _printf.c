#include "main.h"
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
va_start(ap, format);
i = 0;
nb = 0;
while (format && format[i])
{
switch (format[i])
{
case 'c': 
c = va_arg(ap, int);
_putchar(c);
nb++;
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
break;
default: 
_putchar(format[i]);
nb++;
break;
}
i++;
}
_putchar('\n');
va_end(ap);
return ((nb));
}
