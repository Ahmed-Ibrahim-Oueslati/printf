#include "main.h"
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, 'd' or 'i' for integers,
*          'b' for binary, 'u' for unsigned, 'o' for octal,
*          'x' for hex (lowercase), 'X' for hex (uppercase),
*          and '%%' for a literal '%'.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0, length;
char *str;
char c;
int num;
unsigned int unsigned_num;
char buffer[50];
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
case 'd':
case 'i':
num = va_arg(ap, int);
sprintf(buffer, "%d", num);
j = 0;
while (buffer[j] != '\0')
{
_putchar(buffer[j]);
nb++;
j++;
}
break;
case 'b':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_binary(unsigned_num, buffer, sizeof(buffer));
for (j = 0; j < length; j++)
{
_putchar(buffer[j]);
nb++;
}
break;
case 'u':
unsigned_num = va_arg(ap, unsigned int);
sprintf(buffer, "%u", unsigned_num);
j = 0;
while (buffer[j] != '\0')
{
_putchar(buffer[j]);
nb++;
j++;
}
break;
case 'o':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, buffer, sizeof(buffer), 8, 0);
for (j = 0; j < length; j++)
{
_putchar(buffer[j]);
nb++;
}
break;
case 'x':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, buffer, sizeof(buffer), 16, 0);
for (j = 0; j < length; j++)
{
_putchar(buffer[j]);
nb++;
}
break;
case 'X':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, buffer, sizeof(buffer), 16, 1);
for (j = 0; j < length; j++)
{
_putchar(buffer[j]);
nb++;
}
break;
case '%':
_putchar('%');
nb++;
break;
default:
_putchar('%');
_putchar(format[i]);
nb += 2;
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
return ((nb));
}
