/* A C program that shows the relationship between pointers and arrays.

To compile and run this program, type:
clang 01.PointerExercise.c -o 01.PointerExercise && ./01.PointerExercise
*/

#include <stdio.h>

int main() {

  char str[4] = {'a', 'b', 'c','\0'};
  char *pc = str; //Get the base address of an array

  printf("The base address of an array str is: %p\n", pc);

  // Access the first value in the array
  printf("The first value of str is: %c.\n", str[0]);

  // Access the the address of the first value (equivalent to pc = str)
  pc = &str[0]; //Use reference operator to access the address
  printf("The address of the first index in str is: %p.\n", pc);

  //Loop through the addresses of the array
  for (int i = 0; i < 4; i++){
    pc = &str[i];
    printf("The address of the array str at index %d is %p.\n", i, pc);
  }
  
  printf("------------------------------------------\n");
  // Let's try the same with integer type
  int num[4] = {1,2,3,4};
  int *ip = &num[0];

  // Loop through the addresses of the array
  // How does the address increment compared to char type?
  for (int i = 0; i < 4; i++){
    ip = &num[i];
    printf("The address of the array str at index %d is %p.\n", i, ip);
  }

  return 0;
}
