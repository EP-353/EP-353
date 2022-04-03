/* A C program that shows how pointer arithmetic works.

To compile and run this program, type:
clang 03.PointerArithmetic.c -o 03.PointerArithmetic && ./03.PointerArithmetic
*/

#include <stdio.h>

int main() {

  char str[4] = {'a', 'b', 'c', '\0'};
  char *pc = str; // Get the base address of an array
  printf("The base address of an array str is %p with value %c.\n", pc, *pc);
  
  // 1. Increment
  pc = pc + 1; // Same as: pc = &str[1];
  printf("The base address of an array str is %p with value %c.\n", pc, *pc);

  pc += 1; // Increment memory address with the + compound assignment
  printf("The base address of an array str is %p with value %c.\n", pc, *pc);

  pc++; // Increment memory address with the increment operator
  printf("The base address of an array str is %p with value %c.\n", pc, *pc);

  printf("----------------------------------\n");
  // 2. Decrement
  int num[4] = {1,2,3,4};
  int *ip = &num[3]; // Get the last address of an array
  printf("The base address of an array num is %p with value %d.\n", ip, *ip);

  ip = ip - 1; // Same as: ip = &num[2];
  printf("The base address of an array num is %p with value %d.\n", ip, *ip);

  ip -= 1; // Decrement memory address with - compound statement
  printf("The base address of an array num is %p with value %d.\n", ip, *ip);

  ip--; // Decrement memory address with the decrement operator
  printf("The base address of an array num is %p with value %d.\n", ip, *ip);
    
  return 0;
}
