#include <stdlib.h>
#include "main.h"

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
	int o;
  
	o =  _printf("%cc", '%', 'v', '\n');
	printf("%d\n", o);

	return (0);
}

