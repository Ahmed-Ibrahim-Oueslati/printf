#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
* int_to_binary - Converts an unsigned integer to a binary string.
* @num: The unsigned integer to convert.
* @buffer: The buffer to store the binary string.
* @buffer_size: The size of the buffer.
* Return: The length of the binary string.
*/
int int_to_binary(unsigned int num, char *buffer, int buffer_size)
{
int j;
int i = buffer_size - 1;
int length = 0;
if (buffer_size <= 0)
return (0);
buffer[i--] = '\0';
if (num == 0)
{
buffer[i--] = '0';
length = 1;
} 
else
{
while (num > 0 && i >= 0)
{
buffer[i--] = (num % 2) ? '1' : '0';
num /= 2;
length++;
}
for (j = 0; j < length; j++)
buffer[j] = buffer[i + 1 + j];
}
return (length);
}
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, 'd' or 'i' for integers,
*          'b' for binary representation, and '%%' for a literal '%'.
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
unsigned int bin_num;
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
bin_num = va_arg(ap, unsigned int);
length = int_to_binary(bin_num, buffer, sizeof(buffer));
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
