/* Basic modular programming in C. 

To compile and run this program, type:
clang main.c module.c -o main
*/

#include <stdio.h>
#include "module.h" //include module1.h to access the interface

int main() {
  char midi = 69;
  float freq = 440.0f;

  printf("Base frequency is: %f\n", gBaseFreq);
  //Call midi2freq defined in module1.h and module1.c and print out the value
  printf("midi2freq: %d -> %f\n", midi, midi2freq(midi));
  printf("freq2midi: %f -> %d\n", freq, freq2midi(freq));

  return 0;
}