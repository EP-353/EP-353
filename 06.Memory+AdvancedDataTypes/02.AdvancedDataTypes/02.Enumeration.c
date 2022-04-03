/* A program that shows example usage of Enumeration.

To compile and run this program, type:
clang 02.Enumeration.c -o 02.Enumeration && ./02.Enumeration
*/

#include <stdio.h>

//Declare enumeration (typically done outside of the main() function)
enum Waveform {
  sine, triangle, square, sawtooth
};

int main() {  
  //Create an enum variable named Waveform
  enum Waveform waveform;
  waveform = sine; //Asign "sine" constant
  printf("The value of waveform is %d.\n", waveform);

  // But above is a bit cumbersome...
  // Let's shorten it using typedef
  typedef enum Waveform Waveform;
  Waveform wave = square; // Now we can use "Waveform" without the 'enum' keyword
  printf("The value of waveform is %d.\n", wave);

  return 0;
}
