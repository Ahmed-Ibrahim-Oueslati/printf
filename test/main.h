#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int int_to_binary(unsigned int num, char *buffer, int buffer_size);
int int_to_base(unsigned int num, char *buffer, int buffer_size, int base, int uppercase);


#endif 


add to this code so it can Handle the following custom conversion specifier:

r : prints the reversed string



add to this code so it can Handle the following custom conversion specifier:

R: prints the rot13'ed string


add to this code so it can 