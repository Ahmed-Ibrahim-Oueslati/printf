#include "main.h"
/**
* int_to_base - Converts an unsigned integer to a string in a given base.
* @num: The unsigned integer to convert.
* @buffer: The buffer to store the string.
* @buffer_size: The size of the buffer.
* @base: The base to convert to (e.g., 8 for octal, 16 for hexadecimal).
* @uppercase: If 1, use uppercase letters for bases greater than 10.
* Return: The length of the resulting string.
*/
int int_to_base(unsigned int num, char *buffer, int buffer_size, int base, int uppercase)
{
int j;
int i = buffer_size - 1;
const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
int length = 0;
if (buffer_size <= 0)
return (0);
buffer[i--] = '\0';
if (num == 0)
{
buffer[i--] = '0';
length = 1;
} else
{
while (num > 0 && i >= 0)
{
buffer[i--] = digits[num % base];
num /= base;
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
*          'b' for binary, 'u' for unsigned, 'o' for octal,
*          'x' for hex (lowercase), 'X' for hex (uppercase),
*          and '%%' for a literal '%'.
* @...: A variable number of arguments.
* Return: Number of characters printed or -1 on error.
*/