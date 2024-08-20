chat check this function : #include "main.h"

/**
 * _putchar - Entry point of the program.
 *
 * Description: Prints "c"  to the console.
 *@c: char to be printed
 * Return: Always 0 (success).
 */
int _putchar(char c)
{
		return ((write(1, &c, 1)));
}

/**
* _printf - Prints various types of arguments based on a format string.
*
* @format: A string representing the types of arguments passed.
*          'c' for char, 'i' for int, 'f' for float, 's' for string.
* @...: A variable number of arguments.
* Return: void.
*/
int _printf(const char *format, ...)
{
va_list ap;
int i, count, j;
char *str;
char c;
va_start(ap, format);
i = 0;
j = 0;
while (format && format[i])
{
switch (format[i])
{
case 'c':
c = va_arg(ap, int);
_putchar(c);
count = 0;
break;
case '%':
c = va_arg(ap, int);
_putchar('%');
count = 0;
break;
case 's':
str = va_arg(ap, char *);
if (str == NULL)
str = "(nil)";
while (str[j] != '\0')
{
_putchar(str[j]);
j++;
}
count = 0;
break;
default:
count = 1;
break;
}
if (format[i + 1] != '\0' && count == 0)
printf(", ");
i++;
}
_putchar('\n');
va_end(ap);
}
