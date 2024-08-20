#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * flush_buffer - Writes the contents of the buffer to stdout and resets the buffer index.
 * @buffer: The buffer containing the data to be written.
 * @nb: The number of characters in the buffer.
 * Return: The number of characters written.
 */
int flush_buffer(char *buffer, int nb)
{
    write(1, buffer, nb);
    return (0);
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
int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0, j, nb = 0, buffer_index = 0;
    char buffer[BUFFER_SIZE];
    char *str;
    char c;
    int num;
    unsigned int unsigned_num;
    char temp_buffer[50]; // Buffer for integer to string conversion

    if (!format)
        return (-1);

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
                case 'd':
                case 'i':
                    num = va_arg(ap, int);
                    j = sprintf(temp_buffer, "%d", num);
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
                        nb++;
                    }
                    break;
                case 'b':
                    unsigned_num = va_arg(ap, unsigned int);
                    j = int_to_binary(unsigned_num, temp_buffer, sizeof(temp_buffer));
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
                        nb++;
                    }
                    break;
                case 'u':
                    unsigned_num = va_arg(ap, unsigned int);
                    j = sprintf(temp_buffer, "%u", unsigned_num);
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
                        nb++;
                    }
                    break;
                case 'o':
                    unsigned_num = va_arg(ap, unsigned int);
                    j = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 8, 0);
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
                        nb++;
                    }
                    break;
                case 'x':
                    unsigned_num = va_arg(ap, unsigned int);
                    j = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 0);
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
                        nb++;
                    }
                    break;
                case 'X':
                    unsigned_num = va_arg(ap, unsigned int);
                    j = int_to_base(unsigned_num, temp_buffer, sizeof(temp_buffer), 16, 1);
                    for (int k = 0; k < j; k++)
                    {
                        buffer[buffer_index++] = temp_buffer[k];
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

    return (nb);
}
