/* A C program that shows example use of the printf() function.
More info about printf: http://www.cplusplus.com/reference/cstdio/printf/

To compile and run this program, type:
clang 01.printf.c -o 01.printf && ./01.printf
*/

#include <stdio.h>

int main() {
  // Use printf to display formatted output on stdout.
  printf("Hello, World\n");
  printf("%c\n", 'A'); //%c (Character) and argument 'A'
  printf("Note value %d and %d.\n", 69, 72);
  
  // The printf() format specification has the following components:
  // %[flags][width][.precision][length]<specifier>

  //---------- Type Specifiers ----------
  printf("---------- Type Specifiers ----------\n");
  // d or i for signed integers
  printf("Integer: %d\n", 10); // Prints 10
  // x or X for hexadecimal integer
  printf("Hex: %x\n", 10); // Prints 0xa
  // u for unsigned integer
  printf("Unsigned Integer: %u\n", 10); // Prints 10
  // c for character
  printf("Character: %c\n", 'A'); // Prints A
  // s for string
  printf("String: %s\n", "Hello"); // Prints Hello
  // f for float
  printf("Float: %f\n", 2.3); // Prints 2.3
  // % to print out %
  printf("Print %%\n"); // Prints %

  //---------- Flags and Width ----------
  printf("---------- Flags and Width ----------\n");
  // Use + to preceed the result with a plus or minus sign
  printf("%d, %+d, %+d\n", 10, 10, -10); // prints 10, +10, -10
  // 0 left-pads the number with zeroes. # after 0 specifies minimum number of characters to be printed
  printf("%04d\n", 10); // Prints 0010
  // - means left-justify.
  printf("%-7d|\n", 10); // Prints 10•••••| (• is whitespace)

  //---------- Precision ----------
  printf("---------- Precision ----------\n");
  // .2 specifies only up to 2 digits after the decimal point. .0 says no digits after the decimal point.
  printf("%.2f, %.0f\n", 1.132, 1.132); // Prints 1.13, 1
  // .3 specifies print up to 3 digits after the decimal point. Missing digits are filled with 0s.
  printf("%.3f\n", 1.2); // Prints 1.200
  // .3 says print 3 digits. Fill missing digits with 0
  printf("%.3d\n", 10); // Prints 010

  //---------- Type Modifiers ----------
  printf("---------- Type Modifiers ----------\n");
  // h is interpreted as short. Use with i, d, o, u, x, X
  printf("Short Integer: %hd\n", (short) 100);
  // l is interpreted as long. Use with i, d, o, u, x, X
  printf("Long Integer: %ld\n", 100L);
  // L is interpreted as long double. Use with e, f, g
  printf("Long Integer: %Lf\n", (long double) 0.9823);

  return 0;
}