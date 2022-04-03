/* A C program that shows examples of function declaration, definition, and calling. 

To compile and run this program, type:
clang 01.Function.c -o 01.Function && ./01.Function
*/

#include <stdio.h>

// 1. Declare a function through function prototype 
// to let the compiler know
int add(int, int);

// 2. Define the function so that we can call it
int add(int a, int b){
  return a + b;
}

int main() {
  int x = 10, y = 20;
  int z;

  // 3. Call the function
  z = add(x, y);

  // 4. Print out the result
  printf("x + y = %d\n", z);

  return 0;
}