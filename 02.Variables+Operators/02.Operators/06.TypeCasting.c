/* C program that shows examples of cast operator. 

To compile and run this program type:
clang 06.TypeCasting.c -o 06.TypeCasting && ./06.TypeCasting
*/

#include <stdio.h>

int main() {

  // Synthax for type casting
  // (type_name) expression
  float x = 10.3f;
  int y;

  //------------ Implicit and Explicit type casting --------------
  // Assigning float to int 
  // implicitly converts float to int
  y = x;
  printf("Value of y is: %d\n", y);

  // Explicitly type cast float to int
  // Result is the same as above
  float x = 10.3f;
  int y;
  y = (int) x;
  printf("Value of y is: %d\n", y);

  //------------ Type casting in math expression --------------
  // If we just divide two integer type together
  // we do not get the right answer
  int a = 17, b = 5;
  printf("a / b is: %d\n", a / b); // The answer is 3

  // Use type cast to get the correct answer
  float c;
  c = (float) a / b; // convert a to float before dividing
  printf("a / b is: %f\n", c);

  return 0;
}
