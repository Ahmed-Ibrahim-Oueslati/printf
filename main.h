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
int flush_buffer(char *buffer, int nb);

#endif 

