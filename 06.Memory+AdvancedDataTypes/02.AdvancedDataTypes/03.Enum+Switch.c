/* A program that shows example usage of enum with the switch statement.

To compile and run this program, type:
clang 03.Enum+Switch.c -o 03.Enum+Switch && ./03.Enum+Switch
*/

#include <stdio.h>

// Declare enumeration (typically done outside of the main() function)
// Also, create an alias named 'Waveform' in the same statement
typedef enum Waveform {
  sine=1, triangle, square, sawtooth
} Waveform;

int main() {
  // Compiler now understands the 'Waveform' data type
  Waveform waveform;

  // Ask the user to input which waveform they want
  printf("Type in which waveform you would like (1~4).");
  scanf("%d", &waveform);

  // Generate waveform based on the user input
  switch (waveform){
    case sine:
      printf("Sine wave is generated!\n");
      break;
    case triangle:
      printf("Triangle wave is generated!\n");
      break;
    case square:
    printf("Square wave is generated!\n");
    break;
    case sawtooth:
    printf("Sawtooth wave is generated!\n");
    break;
    default:
      printf("That waveform does not exist...\n");
      break;
  }

  return 0;
}
