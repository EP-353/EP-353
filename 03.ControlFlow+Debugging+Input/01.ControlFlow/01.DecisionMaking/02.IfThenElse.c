/* A C program that shows examples of if-then-else statement. 

To compile and run this program, type:
clang 02.IfThenElse.c -o 02.IfThenElse && ./02.IfThenElse
*/

#include <stdio.h>

int main() {  
  int midiNote = 64;

  //---------------------------------------------
  // 1. A basic if-then-else statement 
  // if (/* statement if TRUE */){
  //   /* execute this code when TRUE*/
  // }
  // else {
  //   /* execute this code when FALSE*/
  // }

  // Print a message, if MIDI note is is out of range
  if(midiNote < 0 || midiNote > 127) {
    printf("\nThe note value entered is Invalid.\n");
  }
  else {
    printf("The note value entered is valid.\n");
  }

  //---------------------------------------------
  // 2. Chaining if-then-else statements
  // This example does not use blocks.
  // Once a condition is satisfied, the appropriate statements are executed
  // and the remaining conditions are not evaluated

  if(midiNote < 0)
    printf("\nThe note value entered is Invalid.\n");
  else if(midiNote < 12)
    printf("\nThe note value entered is in octave # -1\n");
  else if(midiNote < 24)
    printf("\nThe note value entered is in octave # 0\n");
  else if(midiNote < 36)
    printf("\nThe note value entered is in octave # 1\n");
  else if(midiNote < 48)
    printf("\nThe note value entered is in octave # 2\n");
  else if(midiNote < 60)
    printf("\nThe note value entered is in octave # 3\n");
  else if(midiNote < 72)
    printf("\nThe note value entered is in octave # 4\n");
  else if(midiNote < 84)
    printf("\nThe note value entered is in octave # 5\n");
  else if(midiNote < 96)
    printf("\nThe note value entered is in octave # 6\n");
  else if(midiNote < 108)
    printf("\nThe note value entered is in octave # 7\n");
  else if(midiNote < 120)
    printf("\nThe note value entered is in octave # 8\n");
  else if(midiNote <= 127)
    printf("\nThe note value entered is in octave # 9\n");
  else 
    printf("\nThe note value entered is Invalid.\n");

  return 0;
}