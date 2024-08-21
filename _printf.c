#include "main.h"
#define BUFFER_SIZE 1024

int _putchar(char c);

void flush_buffer(char *buffer, int length)
{
for (int i = 0; i < length; i++)
_putchar(buffer[i]);
}
/**
* parse_flags - Parses flags, field width, and precision from the format string.
* @format: The format string.
* @index: Pointer to the current index in the format string.
* @flag_plus: Pointer to flag_plus variable.
* @flag_space: Pointer to flag_space variable.
* @flag_hash: Pointer to flag_hash variable.
* @length_modifier: Pointer to length_modifier variable.
* @field_width: Pointer to field_width variable.
* @precision: Pointer to precision variable.
* @pad_char: Pointer to pad_char variable.
*/
void parse_flags(const char *format, int *index, char *flag_plus, char *flag_space,
char *flag_hash, char *length_modifier, int *field_width,
int *precision, char *pad_char)
{
*flag_plus = *flag_space = *flag_hash = 0;
*length_modifier = 0;
*field_width = 0;
*precision = -1;
*pad_char = ' ';

while (format[*index] == '+' || format[*index] == ' ' || format[*index] == '#')
{
if (format[*index] == '+')
*flag_plus = 1;
else if (format[*index] == ' ')
*flag_space = 1;
else if (format[*index] == '#')
*flag_hash = 1;
(*index)++;
}

if (format[*index] >= '0' && format[*index] <= '9')
{
if (format[*index] == '0')
{
*pad_char = '0';
(*index)++;
}
while (format[*index] >= '0' && format[*index] <= '9')
{
*field_width = *field_width * 10 + (format[*index] - '0');
(*index)++;
}
}

if (format[*index] == '.')
{
(*index)++;
*precision = 0;
while (format[*index] >= '0' && format[*index] <= '9')
{
*precision = *precision * 10 + (format[*index] - '0');
(*index)++;
}
}

if (format[*index] == 'l' || format[*index] == 'h')
{
*length_modifier = format[*index];
(*index)++;
}
}
/**
* handle_conversion_specifier - Handles conversion specifiers and formats the output.
* @format: The format string.
* @index: Pointer to the current index in the format string.
* @ap: The variable argument list.
* @buffer: The buffer to store the formatted output.
* @buffer_index: Pointer to the current index in the buffer.
* @field_width: Field width for formatting.
* @precision: Precision for formatting.
* @pad_char: Padding character.
* @flag_plus: Flag for plus sign.
* @flag_space: Flag for space.
* @flag_hash: Flag for hash.
*/
void handle_conversion_specifier(const char *format, int *index, va_list ap, char *buffer,
int *buffer_index, int field_width, int precision,
char pad_char, char flag_plus, char flag_space, char flag_hash)
{
char temp_buffer[50];
int length, j;
char c;
char *str;
long num;
unsigned long unsigned_num;
void *ptr;
switch (format[*index])
{
case 'c':
c = va_arg(ap, int);
buffer[*buffer_index] = c;
(*buffer_index)++;
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
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
j = 0;
while (j < length && str[j] != '\0')
{
buffer[*buffer_index] = str[j];
(*buffer_index)++;
j++;
}
break;
case 'd':
case 'i':
if (format[*index] == 'l')
num = va_arg(ap, long);
else if (format[*index] == 'h')
num = (short)va_arg(ap, int);
else
num = va_arg(ap, int);
if (flag_plus && num >= 0)
{
buffer[*buffer_index] = '+';
(*buffer_index)++;
}
else if (flag_space && num >= 0)
{
buffer[*buffer_index] = ' ';
(*buffer_index)++;
}
sprintf(temp_buffer, "%ld", num);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
j++;
}
break;
case 'b':
unsigned_num = va_arg(ap, unsigned int);
length = int_to_binary(unsigned_num, temp_buffer, sizeof(temp_buffer));
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
for (j = 0; j < length; j++)
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
}
break;
case 'u':
if (format[*index] == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (format[*index] == 'h')
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
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
j++;
}
break;
case 'o':
if (format[*index] == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (format[*index] == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 8, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
for (j = 0; j < length; j++)
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
}
break;
case 'x':
if (format[*index] == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (format[*index] == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
buffer[*buffer_index] = '0';
buffer[*buffer_index + 1] = 'x';
(*buffer_index) += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
for (j = 0; j < length; j++)
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
}
break;
case 'X':
if (format[*index] == 'l')
unsigned_num = va_arg(ap, unsigned long);
else if (format[*index] == 'h')
unsigned_num = (unsigned short)va_arg(ap, unsigned int);
else
unsigned_num = va_arg(ap, unsigned int);
if (flag_hash && unsigned_num != 0)
{
buffer[*buffer_index] = '0';
buffer[*buffer_index + 1] = 'X';
(*buffer_index) += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 1);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[*buffer_index] = '0';
(*buffer_index)++;
}
}
else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
for (j = 0; j < length; j++)
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
}
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
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
j = 0;
while (str[j] != '\0')
{
buffer[*buffer_index] = str[j];
(*buffer_index)++;
j++;
}
}
else
{
buffer[*buffer_index] = '0';
buffer[*buffer_index + 1] = 'x';
(*buffer_index) += 2;
sprintf(temp_buffer, "%lx", (unsigned long)ptr);
length = 0;
while (temp_buffer[length] != '\0')
length++;
if (length + 2 < field_width)
{
for (j = 0; j < field_width - (length + 2); j++)
{
buffer[*buffer_index] = pad_char;
(*buffer_index)++;
}
}
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[*buffer_index] = temp_buffer[j];
(*buffer_index)++;
j++;
}
(*buffer_index) += 2;
}
break;
case '%':
buffer[*buffer_index] = '%';
(*buffer_index)++;
break;
default:
buffer[*buffer_index] = '%';
buffer[*buffer_index + 1] = format[*index];
(*buffer_index) += 2;
break;
}
}
/**
* _printf - Prints various types of arguments based on a format string.
* @format: A string representing the types of arguments passed.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, nb = 0, buffer_index = 0;
char buffer[BUFFER_SIZE];
char flag_plus, flag_space, flag_hash;
char length_modifier;
int field_width, precision;
char pad_char;
if (!format)
return ((-1));
va_start(ap, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
parse_flags(format, &i, &flag_plus, &flag_space, &flag_hash, &length_modifier,
&field_width, &precision, &pad_char);
handle_conversion_specifier(format, &i, ap, buffer, &buffer_index, field_width,
precision, pad_char, flag_plus, flag_space, flag_hash);
}
else
{
buffer[buffer_index] = format[i];
buffer_index++;
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
