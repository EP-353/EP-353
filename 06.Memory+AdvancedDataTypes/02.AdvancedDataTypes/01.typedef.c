/* A program that shows example usage of typedef

To compile and run this program, type:
clang 01.typedef.c -o 01.typedef && ./01.typedef
*/

#include <stdio.h>

// typedef is typically declared outside of the main() function.
// Create an alias named byte that is of type unsigned char.
typedef unsigned char byte;

int main() {  
  // byte is now an alias of unsigned char that compiler understands
  byte ascii = 'a';

  printf("Ascii value is: %c\n", ascii);
  
  return 0;
}
