/* C program that shows examples of compound assignment, increment, and decrement operators. 

To compile and run this program type:
clang 05.Compound.c -o 5.Compound && ./5.Compound
*/

#include <stdio.h>

int main() {
  printf("Compound assignment, increment, and decrement operators in C.\n");
  printf("-------------------------------------------\n");
  
  int a = 4;
  int b = 6;
  int result = 0; 
  
  //Addition
  printf("Addition: %d + ",result);
  result += a + b; //equivalent to result + a + b
  printf("%d + %d = %d\n",a,b,result);
  printf("-------------------------------------------\n");

  //Subtraction
  printf("Subtraction: %d - ",result);
  result -= a; //equivalent to result - a
  printf("%d = %d\n",a,result);
  printf("-------------------------------------------\n");
  
  //Multiplication
  printf("Multiplication: %d * ",result);
  result *= b; //equivalent to result * b
  printf("%d = %d\n",b,result);
  printf("-------------------------------------------\n");

  //Division (Why is the result not correct?)
  printf("Division: %d / ",result);
  result /= a; // equivalent to result / a
  printf("%d = %d\n",a,result);
  printf("-------------------------------------------\n");

  //Remainder (Modulo)
  printf("Modulo: %d %% ",result); //%% to print out % because % is a formatting character in printf
  result %=  b; //equivalent to result % b
  printf("%d = %d\n",b,result);
  printf("-------------------------------------------\n");

  //Increment 
  result = ++a; //prefix increment, meaning the expression evaluates to the final value of x, once it is already increased
  printf("Increment prefix: %d %d\n",a,result);

  result = a++; //suffix increment, meaning the value is also increased, but the expression evaluates to the value that x had before being increased
  printf("Increment suffix: %d %d\n",a,result);
  printf("-------------------------------------------\n");

  //Increment 
  result = --a;
  printf("Decrement prefix: %d %d\n",a,result);

  result = a--;
  printf("Decrement suffix: %d %d\n",a,result);

  return 0;
}
