/* A C program that shows pointer types.

To compile and run this program, type:
clang 02.PointerTypes.c -o 02.PointerTypes && ./02.PointerTypes
*/

#include <stdio.h>

int main() {
  // 1. Pointer data types
  int *ip;    // pointer to an integer
  double *dp; // pointer to a double
  float *fp;  // pointer to a float
  char *cp;   // pointer to a character

  // 2. Type Casting Pointers
  int i = 10;
  ip = &i; // The same pointer type
  dp = &i; // Incompatible pointer type (Compiler will throw a warning)

  // Explicitly type cast int * to double *
  // so that ip and dp points the same memory address
  dp = (double *) ip;

  // Even though ip and dp points to the same memory address,
  // their value will be different when dereferenced
  // ip reads 4 bytes where as dp reads 8 bytes 
  // from the memory address they are pointing to
  printf("The value of ip is: %d. The memory address ip is pointing to is: %p\n", *ip, ip);
  printf("The value of dp is: %f. The memory address dp is pointing to is: %p\n", *dp, dp);

  return 0;
}