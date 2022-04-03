/* A C program that shows examples of if-then statement. 

To compile and run this program, type:
clang 01.IfThen.c -o 01.IfThen && ./01.IfThen
*/

#include <stdio.h>

int main() {  
  int midiNote = 64;

  //---------------------------------------------
  // 1. if-then statement with a single statement
  // if (/* statement is TRUE */)
  //  /* execute this code */

  // Print a message, if MIDI note is is out of range
  if(midiNote < 0 || midiNote > 127) 
    printf("\nThe note value entered is Invalid.\n");

  //---------------------------------------------
  // 2. if-then statement with block 
  // if (/* condition */) {
  //   /* execute this code in the block */
  // }

  // Print a message, if MIDI note is is between 0 and 127
  if(midiNote >= 0 && midiNote <= 127) {
    printf("The note value entered is valid.\n");
    printf("MIDI note value is %d.\n", midiNote);
  } 

  return 0;
}