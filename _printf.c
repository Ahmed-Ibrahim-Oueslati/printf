#include "main.h"
/**
* _putchar - Prints a single character to the console.
* @c: The character to be printed.
* Return: On success, returns the number of characters printed (1).
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return ((write(1, &c, 1)));
}
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, '%%' for percent sign.
* @...: A variable number of arguments.
* Return: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0;
char *str;
va_start(ap, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
nb += 
_putchar(va_arg(ap, int));
break;
case 's':
str = va_arg(ap, char *);
if (!str)
str = "(nil)";
j = 0;
while (str[j])
nb += 
_putchar(str[j++]);
break;
case '%':
nb += 
_putchar('%');
break;
default:
nb += 
_putchar('%');
nb += 
_putchar(format[i]);
break;
}
}
else
{
	nb +=
	_putchar(format[i]);
}
i++;
}
va_end(ap);
return ((nb));
}
