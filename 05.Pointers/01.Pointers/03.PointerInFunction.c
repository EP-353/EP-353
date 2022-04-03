/* A C program that shows how to use pointers with functions.

To compile and run this program, type:
clang 03.PointerInFunction.c -o 03.PointerInFunction && ./03.PointerInFunction
*/

#include <stdio.h>

void swap(int a, int b);
void swapWithPointer(int *a, int *b);

int main() {
  int value1 = 10, value2 = 20;
  printf("Values before swapping: value1 -> %d, value2 ->  %d.\n", value1, value2);
  
  // Any changes we make to the variables passed in to the function 
  // will be disregarded once the function exits.
  // This happens because fo how functions work with regard to stack memory:
  // Parameters of a function are the copies of the original values
  // passed down through calling that function.
  swap(value1, value2);
  printf("Values after swapping without pointer: value1 -> %d, value2 ->  %d.\n", value1, value2);

  // By passing the address of the variable instead of the value (call by reference),
  // any changes made by the function using the pointer remains even after the function exists.
  swapWithPointer(&value1, &value2);
  printf("Values after swapping with pointer: value1 -> %d, value2 ->  %d.\n", value1, value2);

  return 0;
}

void swap(int a, int b){
  int c = a;
  a = b;
  b = c;
}

void swapWithPointer(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}