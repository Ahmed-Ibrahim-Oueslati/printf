#include "main.h"
#define BUFFER_SIZE 1024
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, 'd' or 'i' for integers,
*          'b' for binary, 'u' for unsigned, 'o' for octal,
*          'x' for hex (lowercase), 'X' for hex (uppercase),
*          'S' for string with non-printable characters as \xXX,
*          and '%%' for a literal '%'.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0, buffer_index = 0, length;
char *str;
char c;
int num;
unsigned int unsigned_num;
char temp_buffer[50];
char buffer[BUFFER_SIZE];
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
buffer[buffer_index++] = c;
nb++;
break;
case 's':
str = va_arg(ap, char *);
if (str == NULL)
str = "(nil)";
j = 0;
while (str[j] != '\0')
{
buffer[buffer_index++] = str[j];
nb++;
j++;
}
break;
case 'S':
str = va_arg(ap, char *);
if (str == NULL)
str = "(nil)";
j = 0;
while (str[j] != '\0')
{
if (str[j] < 32 || str[j] >= 127)
{
buffer[buffer_index++] = '\\';
buffer[buffer_index++] = 'x';
sprintf(temp_buffer, "%02X", (unsigned char)str[j]);
buffer[buffer_index++] = temp_buffer[0];
buffer[buffer_index++] = temp_buffer[1];
nb += 4;
}
else
{
buffer[buffer_index++] = str[j];
nb++;
}
j++;
}
break;
case 'd':
case 'i':
num = va_arg(ap, int);
sprintf(temp_buffer, "%d", num);
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
j++;
}
break;
case 'b':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_binary(unsigned_num, temp_buffer, sizeof(temp_buffer));
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
break;
case 'u':
unsigned_num = va_arg(ap, unsigned int);
sprintf(temp_buffer, "%u", unsigned_num);
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
j++;
}
break;
case 'o':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 8, 0);
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
break;
case 'x':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 0);
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
break;
case 'X':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 1);
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
break;
case '%':
buffer[buffer_index++] = '%';
nb++;
break;
default:
buffer[buffer_index++] = '%';
buffer[buffer_index++] = format[i];
nb += 2;
break;
}
}
else
{
buffer[buffer_index++] = format[i];
nb++;
}
if (buffer_index >= BUFFER_SIZE)
{
flush_buffer(buffer, buffer_index);
buffer_index = 0;
}
i++;
}
if (buffer_index > 0)
flush_buffer(buffer, buffer_index);
va_end(ap);
return ((nb));
}
