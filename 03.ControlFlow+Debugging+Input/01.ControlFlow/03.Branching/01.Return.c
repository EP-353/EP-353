/* A C program that shows examples of branching statement. 

To compile and run this program, type:
clang 01.Return.c -o 01.Return && ./01.Return
*/

#include <stdio.h>

int main() {
  // return statement
  return 0;
  // Any codes below return statement will not be executed
  // because the statement causes to exit the current function.
  // There will be no print out on the console with the following printf function
  printf("This will not be printed on the console.\n");
}

