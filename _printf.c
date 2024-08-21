#include "main.h"
#define BUFFER_SIZE 1024

int int_to_binary(unsigned int num, char *buffer, int buffer_size)
{
int i = buffer_size - 1;
buffer[i] = '\0';
while (i >= 0 && num > 0)
{
buffer[i] = (num % 2) + '0';
num /= 2;
i--;
}
return (i + 1);
}
int int_to_base(unsigned int num, char *buffer, int buffer_size, int base, int uppercase)
{
int i = buffer_size - 1;
buffer[i] = '\0';
while (i >= 0 && num > 0)
{
int digit = num % base;
if (digit < 10)
{
	buffer[i] = digit + '0';
} else
{
	buffer[i] = (digit - 10) + (uppercase ? 'A' : 'a');
}
num /= base;
i--;
}
return (i + 1);
}
void flush_buffer(char *buffer, int buffer_index)
{
	write(1, buffer, buffer_index);
}

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
char flag_plus = 0, flag_space = 0, flag_hash = 0;
char length_modifier = 0;
int field_width = 0;
int precision = -1;
char pad_char = ' ';
if (!format)
{
	return (-1);
}
va_start(ap, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
flag_plus = flag_space = flag_hash = 0;
length_modifier = 0;
field_width = 0;
precision = -1;
pad_char = ' ';
while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
{
if (format[i] == '+')
{
	flag_plus = 1;
} else if (format[i] == ' ')
{
	flag_space = 1;
} else if (format[i] == '#')
{
	flag_hash = 1;
}
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
buffer[buffer_index++] = c;
nb++;
break;
case 's':
str = va_arg(ap, char *);
if (str == NULL)
{
	str = "(nil)";
}
length = 0;
while (str[length] != '\0')
{
	length++;
}
if (precision >= 0 && precision < length)
{
	length = precision;
}
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
j = 0;
while (j < length && str[j] != '\0')
{
buffer[buffer_index++] = str[j];
nb++;
j++;
}
break;
case 'd':
case 'i':
if (length_modifier == 'l')
{
	num = va_arg(ap, long);
} else if (length_modifier == 'h')
{
	num = (short)va_arg(ap, int);
} else
{
	num = va_arg(ap, int);
}
if (flag_plus && num >= 0)
{
buffer[buffer_index++] = '+';
nb++;
} else if (flag_space && num >= 0)
{
buffer[buffer_index++] = ' ';
nb++;
}
sprintf(temp_buffer, "%ld", num);
length = 0;
while (temp_buffer[length] != '\0')
{
	length++;
}
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
} else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
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
if (length < field_width)
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
break;
case 'u':
if (length_modifier == 'l')
{
	unsigned_num = va_arg(ap, unsigned long);
} else if (length_modifier == 'h')
{
	unsigned_num = (unsigned short)va_arg(ap, unsigned int);
} else
{
	unsigned_num = va_arg(ap, unsigned int);
}
sprintf(temp_buffer, "%lu", unsigned_num);
length = 0;
while (temp_buffer[length] != '\0')
{
	length++;
}
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
} else if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
j++;
}
break;
case 'o':
if (length_modifier == 'l')
{
	unsigned_num = va_arg(ap, unsigned long);
} else if (length_modifier == 'h')
{
	unsigned_num = (unsigned short)va_arg(ap, unsigned int);
} else
{
	unsigned_num = va_arg(ap, unsigned int);
}
if (flag_hash && unsigned_num != 0)
{
buffer[buffer_index++] = '0';
nb++;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 8, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
} else if (length < field_width)
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
break;
case 'x':
if (length_modifier == 'l')
{
	unsigned_num = va_arg(ap, unsigned long);
} else if (length_modifier == 'h')
{
	unsigned_num = (unsigned short)va_arg(ap, unsigned int);
} else
{
	unsigned_num = va_arg(ap, unsigned int);
}
if (flag_hash && unsigned_num != 0)
{
buffer[buffer_index++] = '0';
buffer[buffer_index++] = 'x';
nb += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 0);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
} else if (length < field_width)
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
break;
case 'X':
if (length_modifier == 'l')
{
	unsigned_num = va_arg(ap, unsigned long);
} else if (length_modifier == 'h')
{
	unsigned_num = (unsigned short)va_arg(ap, unsigned int);
} else
{
	unsigned_num = va_arg(ap, unsigned int);
}
if (flag_hash && unsigned_num != 0)
{
buffer[buffer_index++] = '0';
buffer[buffer_index++] = 'X';
nb += 2;
}
length = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 1);
if (precision > length)
{
for (j = 0; j < precision - length; j++)
{
buffer[buffer_index++] = '0';
nb++;
}
} else if (length < field_width)
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
break;
case 'p':
ptr = va_arg(ap, void *);
if (ptr == NULL)
{
str = "(nil)";
length = 0;
while (str[length] != '\0')
{
	length++;
}
if (length < field_width)
{
for (j = 0; j < field_width - length; j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
j = 0;
while (str[j] != '\0')
{
buffer[buffer_index++] = str[j];
nb++;
j++;
}
} else
{
buffer[buffer_index++] = '0';
buffer[buffer_index++] = 'x';
sprintf(temp_buffer, "%lx", (unsigned long)ptr);
length = 0;
while (temp_buffer[length] != '\0')
{
	length++;
}
if (length + 2 < field_width)
{
for (j = 0; j < field_width - (length + 2); j++)
{
buffer[buffer_index++] = pad_char;
nb++;
}
}
j = 0;
while (temp_buffer[j] != '\0')
{
buffer[buffer_index++] = temp_buffer[j];
nb++;
j++;
}
nb += 2;
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
} else
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
{
	flush_buffer(buffer, buffer_index);
}
va_end(ap);
return (nb);
