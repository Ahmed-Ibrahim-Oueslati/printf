#include "main.h"

/**
 * select_f - Select a function based on the format specifier.
 * @spe: The format specifier in the format string.
 * @p: Pointer to a function pointer that will be assigned the appropriate function.
 * 
 * Return: void
 */
void select_f(char spe, int (**p)(va_list))
{
    if (spe == 'd' || spe == 'i')
        *p = print_int;
    else if (spe == 'c')
        *p = print_char;
    else if (spe == 's')
        *p = print_str;
    else if (spe == '%')
        *p = print_percent;
    else if (spe == 'b')
        *p = print_binary;
    else if (spe == 'r')
        *p = print_reversed;
    else if (spe == 'p')
        *p = print_address;
    else if (spe == 'R')
        *p = rot13;
    else if (spe == 'u')
        *p = unsigned_integer;
    else if (spe == 'o')
        *p = print_octal;
    else if (spe == 'x')
        *p = print_hex;
    else if (spe == 'X')
        *p = print_HEX;
    else
        *p = NULL;  /* Unsupported specifier */
}

/**
* _printf - Prints formatted text to stdout.
* @format: The format string.
* @...: The arguments to print.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0, nb = 0;
    char *str;
    int (*p)(va_list) = NULL;  /* Function pointer for handling specifiers */
    char specifier;

    if (format == NULL)
        return (-1);

    va_start(ap, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            specifier = format[i];
            /* Function selection for specifier */
            select_f(specifier, &p);

            if (p != NULL)
            {
                nb += p(ap);  /* Call the appropriate function */
            }
            else
            {
                /* Handle unsupported specifiers */
                nb += _putchar('%');
                nb += _putchar(format[i]);
            }
        }
        else
        {
            nb += _putchar(format[i]);
        }
        i++;
    }

    va_end(ap);
    return (nb);
}
