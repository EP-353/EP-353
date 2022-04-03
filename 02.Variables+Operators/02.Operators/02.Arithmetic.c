/* C program that shows examples of arithmetic operators. 

To compile and run this program type:
clang 02.Arithmetic.c -o 02.Arithmetic && ./02.Arithmetic
*/

#include <stdio.h>

int main() {
  printf("-------------------------------------------\n");
  
  int a = 4;
  int b = 6;
  int c = 10;
  int result; 
  
  //Addition
  result = a + b + c;
  printf("Addition: %d + %d + %d = %d\n",a,b,c,result);
  printf("-------------------------------------------\n");

  //Subtraction
  result = a - b - c;
  printf("Subtraction: %d - %d - %d = %d\n",a,b,c,result);
  printf("-------------------------------------------\n");
  
  //Multiplication
  result = a * b * c;
  printf("Multiplication: %d * %d * %d = %d\n",a,b,c,result);
  printf("-------------------------------------------\n");

  //Division (Why is the result not correct?)
  result = c / a;
  printf("Division: %d / %d = %d\n",c,a,result);
  printf("-------------------------------------------\n");

  //Remainder (Modulo)
  result =  c % a;
  printf("Modulo: %d %% %d = %d\n",c,a,result); //%% to print out % because % is a formatting character in printf
  
  return 0;
}
