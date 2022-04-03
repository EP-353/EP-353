/* A C program example of local and global variables. 

To compile and run this program, type:
clang 01.GlobalVariable.c -o 01.GlobalVariable && ./01.GlobalVariable
*/

#include <stdio.h>

int foo; // Global Variable

void func(){
  int bar = 0; // Local Variable
  // Local variable bar disappears after func() exists
}

int main(){
  int me; // Local Variable 
  //foo is accessible by main()
  printf("foo is: %d\n", foo);
  //bar is not accessible by main()
  printf("bar is: %d\n", bar);
  //me is accessible by main()
  printf("me is: %d\n", me);
}