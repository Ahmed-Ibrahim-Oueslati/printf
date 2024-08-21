#include "main.h"
#define BUFFER_SIZE 1024

int _putchar(char c);

void flush_buffer(char *buffer, int length)
{
for (int i = 0; i < length; i++)
_putchar(buffer[i]);
}
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
*          'c' for char, 's' for string, 'd' or 'i' for integers,
*          'b' for binary, 'u' for unsigned, 'o' for octal,
*          'x' for hex (lowercase), 'X' for hex (uppercase),
*          'S' for string with non-printable characters as \xXX,
*          'p' for pointer, 'r' for reversed string, and '%%' for a literal '%'.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, j, nb = 0;
char *str;
char c;
long num;
unsigned long unsigned_num;
void *ptr;
char temp_buffer[50];
char flag_plus = 0, flag_space = 0, flag_hash = 0, flag_minus = 0;
char length_modifier = 0;
int field_width = 0;
int precision = -1;
char pad_char = ' ';
if (!format)
return ((-1));
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
if (format[i] == '0')
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
if (flag_minus)
{
_putchar(c);
for (j = 1; j < field_width; j++)
{
_putchar(' ');
nb++;
}
}
else
{
for (j = 1; j < field_width; j++)
{
_putchar(pad_char);
nb++;
}
_putchar(c);
}
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
for (j = 0; j < length; j++)
_putchar(str[j]);
while (j < field_width)
{
_putchar(' ');
nb++;
j++;
}
}
else
{
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(str[j]);
}
nb += length;
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
_putchar('+');
else if (flag_space && num >= 0)
_putchar(' ');
sprintf(temp_buffer, "%ld", num);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
_putchar('0');
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'b':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_binary(unsigned_num, temp_buffer, sizeof(temp_buffer));
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'u':
if (length_modifier == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (length_modifier == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
sprintf(temp_buffer, "%lu", unsigned_num);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
_putchar('0');
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'o':
if (length_modifier == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (length_modifier == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
_putchar('0');
nb++;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 8, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
_putchar('0');
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'x':
if (length_modifier == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (length_modifier == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
_putchar('0');
_putchar('x');
nb += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
_putchar('0');
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'X':
if (length_modifier == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (length_modifier == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
_putchar('0');
_putchar('X');
nb += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 1);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
_putchar('0');
nb++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += length;
break;
case 'p':
ptr = va_arg(ap, void *);
if (ptr == NULL)
{
str = "(nil)";
length = 0;
while (str[length] != '\0')
length++;
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(str[j]);
}
else
{
_putchar('0');
_putchar('x');
sprintf(temp_buffer, "%lx", (unsigned long)ptr);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (length + 2 < field_width)
{
for (j = 0; j < field_width - (length + 2); j++)
{
_putchar(pad_char);
nb++;
}
}
for (j = 0; j < length; j++)
_putchar(temp_buffer[j]);
nb += 2;
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

int int_to_binary(unsigned int num, char *buffer, size_t buffer_size)
{
int i = 0;
if (buffer_size == 0)
return (0);
do
{
if (i >= buffer_size - 1)
break;
buffer[i++] = (num & 1) ? '1' : '0';
num >>= 1;
} while (num != 0);
buffer[i] = '\0';

for (int start = 0, end = i - 1; start < end; start++, end--)
{
char temp = buffer[start];
buffer[start] = buffer[end];
buffer[end] = temp;
}
return (i);
}

int int_to_base(unsigned long num, char *buffer, size_t buffer_size, int base, int uppercase)
{
const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
int i = 0;
if (base < 2 || base > 16)
return (0);
do
{
if (i >= buffer_size - 1)
break;
buffer[i++] = digits[num % base];
num /= base;
} while (num != 0);
buffer[i] = '\0';

for (int start = 0, end = i - 1; start < end; start++, end--)
{
char temp = buffer[start];
buffer[start] = buffer[end];
buffer[end] = temp;
}
return (i);
}
