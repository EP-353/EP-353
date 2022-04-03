/* A C program example of a static variable. 

To compile and run this program, type:
clang 03.StaticVariable.c -o 03.StaticVariable && ./03.StaticVariable
*/

#include <stdio.h>

//A function with static variable
void func(){
  static int foo = 20;
  printf("%d\n", foo);
  foo++;
}

int main(){
  for(int i = 0; i < 10; i++){
    func();
   }
  return 0;
}