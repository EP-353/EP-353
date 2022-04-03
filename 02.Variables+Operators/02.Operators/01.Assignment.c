/* C program that shows examples of assignment operators. 
Assignment operator always operates from right-to-left.

To compile and run this program type:
clang 01.Assignment.c -o 01.Assignment && ./01.Assignment
*/

#include <stdio.h>

int main() {
  printf("-------------------------------------------\n");
  
  int a, b; //Declare integer variable a and b. Their values are initially unknown.
  a = 10; //Assign 10 to the variable a. The value of variable b is still unknown.
  b = 4; //Assign 4 to the variable b.

  printf("The value of variable a is: %d\n",a);
  printf("The value of variable b is: %d\n",b);
  printf("-------------------------------------------\n");

  //Assign b to a, then assign a new value to b
  a = b;
  b = 7;

  printf("The value of variable a is: %d\n",a);
  printf("The value of variable b is: %d\n",b);
  printf("-------------------------------------------\n");
  
  //Assign a and b the same value
  a = b = 13;
  
  printf("The value of variable a is: %d\n",a);
  printf("The value of variable b is: %d\n",b);

  return 0;
}
