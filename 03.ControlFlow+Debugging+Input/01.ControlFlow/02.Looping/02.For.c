/* A C program that shows examples of for loop statement. 

To compile and run this program, type:
clang 02.For.c -o 02.For && ./02.For
*/

#include <stdio.h>

int main() {
  // for loop mechanism:
  // 1. Set i to an initial value of 0 (Initialization)
  // 2. Set the condition to terminate the loop (Condition)
  // 3. Increment i after each looping step (update)
  for(int i = 0; i < 128; i++) {
    printf("The next MIDI note value is %d\n", i);
  }
  printf("--------------------------------\n");
  
  // Decrement i instead
  for(int i = 127; i >= 0; i--) {
    printf("The next MIDI note value is %d\n", i);
  }
  printf("--------------------------------\n");

  //Increment i by 2
  for(int i = 0; i < 128; i+=2) {
    printf("The next MIDI note value is %d\n", i);
  }

  return 0;
}