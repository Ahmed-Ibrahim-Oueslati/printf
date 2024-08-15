printf Clone
This repository contains a custom implementation of the standard printf function in C. The printf function is commonly used to output formatted strings to the console. This project aims to replicate its functionality as closely as possible while also providing a deeper understanding of variadic functions, string manipulation, and output formatting.

Features:

Supports the following format specifiers: %c for characters, %s for strings, %d and %i for integers, %u for unsigned integers, %x and %X for hexadecimal numbers (lowercase and uppercase), %o for octal numbers, %p for pointers, and %% for a literal percent sign.
Handles edge cases such as null strings, large integers, and mixed format specifiers.
Files:

_printf.c: Contains the main implementation of the printf function.
main.h: Header file with function prototypes and necessary libraries.
helper_functions.c: Contains helper functions used by _printf, such as string manipulation and number conversion.
man_3_printf.3: Manual page for the _printf function.
tests/: Directory containing various test cases to validate the functionality of _printf.
Usage:
To use this printf clone in your project, follow these steps:

Clone the repository: git clone https://github.com/yourusername/printf_clone.git and navigate into the directory using cd printf_clone.
Compile the code: gcc _printf.c -o printf_clone.
Include it in your project: Add the main.h file to your project and compile with your other source files.
Example:
c
Copy code
#include "main.h"

int main(void) {
    _printf("Hello, %s!\n", "world");
    return (0);
}
