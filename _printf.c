#include "main.h"
#define BUFFER_SIZE 1024
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0, buffer_index = 0, length;
char *str;
char c;
long num;
unsigned long unsigned_num;
void *ptr;
char temp_buffer[50];
char buffer[BUFFER_SIZE];
char flag_plus = 0, flag_space = 0, flag_hash = 0, flag_minus = 0;
char length_modifier = 0;
int field_width = 0;
int precision = -1;
char pad_char = ' ';
if (!format)
return (((-1)));
va_start(ap, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
flag_plus = flag_space = flag_hash = flag_minus = 0;
length_modifier = 0;
field_width = 0;
precision = -1;
pad_char = ' ';

while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '-')
{
if (format[i] == '+')
flag_plus = 1;
else if (format[i] == ' ')
flag_space = 1;
else if (format[i] == '#')
flag_hash = 1;
else if (format[i] == '-')
flag_minus = 1;
i++;
}

if (format[i] >= '0' && format[i] <= '9')
{
if (format[i] == '0' && !flag_minus) 
{
pad_char = '0';
i++;
}
while (format[i] >= '0' && format[i] <= '9')
{
field_width = field_width * 10 + (format[i] - '0');
i++;
}
}

if (format[i] == '.')
{
i++;
precision = 0;
while (format[i] >= '0' && format[i] <= '9')
{
precision = precision * 10 + (format[i] - '0');
i++;
}
}

if (format[i] == 'l' || format[i] == 'h')
{
length_modifier = format[i];
i++;
}

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
length = 0;
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (flag_minus) 
{
for (j = 0; j < length && str[j] != '\0'; j++)
{
buffer[buffer_index++] = str[j];
nb++;
}
for (; j < field_width; j++)
{
buffer[buffer_index++] = ' ';
nb++;
}
}
else 
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
for (j = 0; j < length && str[j] != '\0'; j++)
{
buffer[buffer_index++] = str[j];
nb++;
}
}
break;
case 'd':
case 'i':
if (length_modifier == 'l')
num = va_arg(ap, long);
else if (length_modifier == 'h')
num = (short)va_arg(ap, int);
else
num = va_arg(ap, int);
if (flag_plus && num >= 0)
{
buffer[buffer_index++] = '+';
nb++;
}
else if (flag_space && num >= 0)
{
buffer[buffer_index++] = ' ';
nb++;
}
sprintf(temp_buffer, "%ld", num);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (flag_minus) 
{
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
for (; j < field_width; j++)
{
buffer[buffer_index++] = ' ';
nb++;
}
}
else 
{
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
for (j = 0; j < length; j++)
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
}
}
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
