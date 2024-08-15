#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: Prints a string to the console.
 *
 * Return: Always 0 (success).
 */
/*%c print a single character
%d print a decimal (base 10) number
%e print an exponential floating-point number
%f print a floating-point number
%g print a general-format floating-point number
%i print an integer in base 10
%o print a number in octal (base 8)
%s print a string of characters
%u print an unsigned decimal (base 10) number
%x print a number in hexidecimal (base 16)
%% print a percent sign (\% also works)

\a audible alert (bell)
\b backspace
\f form feed
\n newline (linefeed)
\r carriage return
\t tab
\v vertical tab

\ escape the next character
\\ print a backslash
" start or end of string
\" print a double quote
’ start or end a character constant
\’ print a single quote
% start a format specification
\% print a percent sign



*/
int main(void)
{
int k, l, i; 
char *pm;
float oh;
oh = 859,45821;
pm = "hello";
k = 787;
printf("%5d\n", k);
printf("%-5d\n", k);
printf("%05d\n", k);
printf("%+5d\n", k);
/*printf("%+5d\n", k); == printf("% 5d\n", k);*/
printf("% -5d\n", k);
printf("% 05d\n", k);
printf("%+05d\n", k);
printf("%2s\n", pm);
printf("%.f\n", oh);
printf("%.0f.\n", oh);
printf("%.10f.\n", oh);
printf("%5.7f\n", oh);
return 0;
}
