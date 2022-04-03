/* A C program example of local and global variables. 
Try to guess how many lines of line will be printed out before running.

To compile and run this program, type:
clang 02.HowManLines.c -o 02.HowManLines && ./02.HowManLines
*/

#include <stdio.h>
int count = 20;

int main(){
  int a = 0, b = 1, c, count = 25;
  for (int i = 0; i < count; i++)
  {
    c = a + b;
    a = b;
    b = c;
    printf("%d: %d\n", i, c);
  }
  return 0;
}