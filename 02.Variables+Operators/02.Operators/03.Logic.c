/* C program that shows examples of logical operators. 

To compile and run this program type:
clang 03.Logic.c -o 03.Logic && ./03.Logic
*/

#include <stdio.h>
#include <stdbool.h> //Include this library to get the boolean type

int main() {
  printf("Boolean algebra and logical operators in C using NOT(!), AND(&&), and OR(||).\n");
  printf("-------------------------------------------\n");

  //Boolean logic deals in values of true and false.
  //In C, 0 is false. Anything non-zero is true, but typically 1 is true.
  
  //The logical operators are 
  // && - and
  // || - or
  // ! - negation (sometimes call "not")

  // order of precendece is !, &&, ||

  bool a, b, result;
  
  a = b = true; //Assign true to both
  printf("a = %d, b = %d\n", a, b);

  result = !a; // invert the truth value of a
  printf("!a = %d\n", result);
  result = !b; // invert the truth value of b
  printf("!b = %d\n", result);
  result = a && b; // check out "and" for them and print a result
  printf("a && b = %d\n", result);
  result = a || b; // check out "or" for them and print another result
  printf("a || b = %d\n", result);
  printf("-------------------------------------------\n");

  a = false; //Assign false to a
  printf("a = %d, b = %d\n", a, b);

  result = !a; // invert the truth value of a
  printf("!a = %d\n", result);
  result = !b; // invert the truth value of b
  printf("!b = %d\n", result);
  result = a && b; // check out "and" for them and print a result
  printf("a && b = %d\n", result);
  result = a || b; // check out "or" for them and print another result
  printf("a || b = %d\n", result);
  printf("-------------------------------------------\n");

  b = false; //Assign false to b
  printf("a = %d, b = %d\n", a, b);

  result = !a; // invert the truth value of a
  printf("!a = %d\n", result);
  result = !b; // invert the truth value of b
  printf("!b = %d\n", result);
  result = a && b; // check out "and" for them and print a result
  printf("a && b = %d\n", result);
  result = a || b; // check out "or" for them and print another result
  printf("a || b = %d\n", result);
  printf("-------------------------------------------\n");

  return 0;
}
