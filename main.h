#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
void select_f(char spe, int (**p)(va_list));


#endif 