/* A C program for demonstrating exit codes.
Use "echo $?" to display the exit code after executing this code.

To compile and run this program, type:
clang 01.ExitCode.c -o 01.ExitCode && ./01.ExitCode
*/

#include <stdio.h>
int main()
{
  int number = 0;
  printf("Type in a number: ");
  scanf("%d", &number);

  if (number != 2)
  {
    printf("The number is not 2. Exiting...\n");
    return 1; 
  }
  printf("hello, %d\n", number);
  return 0; 
}