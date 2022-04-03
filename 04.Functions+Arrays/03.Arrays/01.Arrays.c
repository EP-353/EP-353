/* A C program that shows the basic use of arrays in C.

To compile and run this program, type:
clang 01.Arrays.c -o 01.Arrays && ./01.Arrays
*/

#include <stdio.h>

int main() {

  // Syntax for declaring array
  // type name[size];
  int data[10];

  // Initialize array with curly brackets
  int numbers[4] = {5, 3, 0, 6};
  // Array size can be omitted if curly brackets is used
  int nums[] = {5, 3, 0, 6};

  // Accessing an element of array by indexing
  printf("%d\n", nums[0]); //First index
  printf("%d\n", nums[2]); //Third index
  printf("%d\n", nums[3]); //Last index

  // We can also initialize an array using for-loop and indexing
  for (int i = 0; i < 10; i++) {
    data[i] = i * i;
  }
  
  // Access each element in an array using for-loop
  for (int i = 0; i < 10; i++) {
    printf("data array on index %d contains %d.\n", i, data[i]);
  }

  return 0;
}