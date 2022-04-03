/* C program that shows examples of relational and comparison operators. 

To compile and run this program type:
clang 04.Comparison.c -o 04.Comparison && ./04.Comparison
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("Relational and comparison operators in C.\n");
  printf("-------------------------------------------\n");
  
  int a, b;
  bool result; 
  
  //a is greater than b
  a = 11;
  b = 10;

  printf("a = %d, b = %d\n", a, b);

  //Run through the full set of comparison operations
  result = a < b;
  printf("a < b = %d\n", result);

  result = a <= b;
  printf("a <= b = %d\n", result);

  result = a == b;
  printf("a == b = %d\n", result);

  result = a != b;
  printf("a != b = %d\n", result);

  result = a > b;
  printf("a > b = %d\n", result);

  result = a >= b;
  printf("a >= b = %d\n", result);
  printf("-------------------------------------------\n");

  a = 9; //a is now less than b

  printf("a = %d, b = %d\n", a, b);

  result = a < b;
  printf("a < b = %d\n", result);

  result = a <= b;
  printf("a <= b = %d\n", result);

  result = a == b;
  printf("a == b = %d\n", result);

  result = a != b;
  printf("a != b = %d\n", result);

  result = a > b;
  printf("a > b = %d\n", result);

  result = a >= b;
  printf("a >= b = %d\n", result);

  printf("-------------------------------------------\n");
  a = 10; //a is equal to b

  printf("a = %d, b = %d\n", a, b);

  result = a < b;
  printf("a < b = %d\n", result);

  result = a <= b;
  printf("a <= b = %d\n", result);

  result = a == b;
  printf("a == b = %d\n", result);

  result = a != b;
  printf("a != b = %d\n", result);

  result = a > b;
  printf("a > b = %d\n", result);

  result = a >= b;
  printf("a >= b = %d\n", result);
  return 0;
}
