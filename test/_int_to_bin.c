#include "main.h"
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