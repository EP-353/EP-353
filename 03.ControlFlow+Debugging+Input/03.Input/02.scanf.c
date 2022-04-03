/* A C program that shows example use of the printf() function.
More info about printf: http://www.cplusplus.com/reference/cstdio/printf/

To compile and run this program, type:
clang 02.scanf.c -o 02.scanf && ./02.scanf
*/

#include <stdio.h>

int main() {
  int x;
  float f;
  // Use scanf to get formatted input from stdin.
  // The scanf() has the same format specification as printf()
  printf("Type in an integer value: ");
  scanf("%d", &x); //& means the address of variable x
  printf("You typed in an integer value: %d\n\n", x); 
  
  printf("Type in a floating-point value: ");
  scanf("%f", &f); // get floating-point value
  printf("You typed in a floating-point value: %f\n\n", f); 

  return 0;
}