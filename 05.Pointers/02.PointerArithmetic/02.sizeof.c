/* A C program that shows the use of sizeof() operator.

To compile and run this program, type:
clang 02.sizeof.c -o 02.sizeof && ./02.sizeof
*/

#include <stdio.h>

int main() {
  // sizeof() gives us the size of data types, variables, pointers, arrays, etc. in bytes
  // Syntax: sizeof(datatype)
  int byteSize = sizeof(char); // should be 1
  printf("Byte size of char is: %d.\n", byteSize);
  byteSize = sizeof(double); // should be 8 for 64-bit machines
  printf("Byte size of double is: %d.\n", byteSize);

  //Get size of arrays in bytes
  char str[4];
  byteSize = sizeof(str); //should be 4
  printf("Byte size of str is: %d.\n", byteSize);
  int num[4];
  byteSize = sizeof(num); //should be 16 for 64-bit machines
  printf("Byte size of num is: %d.\n", byteSize);

  //A trick to find the actual length of an array
  int length = sizeof(num) / sizeof(num[0]);
  printf("Size of num is: %d.\n", length);

  return 0;
}
