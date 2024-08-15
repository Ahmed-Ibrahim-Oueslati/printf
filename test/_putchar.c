#include "main.h"
/**
* _putchar - Prints a character to the console.
* @c: The character to print.
* Return: Number of characters printed.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}