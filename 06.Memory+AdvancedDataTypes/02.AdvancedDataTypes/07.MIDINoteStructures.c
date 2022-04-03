/* A program that shows example usage of structure.

To compile and run this program, type:
clang 07.MIDINoteSturectures.c -o 07.MIDINoteSturectures && ./07.MIDINoteSturectures
*/

#include <stdio.h>

// Syntax for structure:
// struct tag { 
// 	type name; type name; ... 
// };

struct Note {
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
}; //Semi-column at the end

//Let's typedef to avoid typing 'struct' again.
typedef struct Note Note;

const int NOTES = 10;

int main() {
  //Define a variable note of type Note, and initialize its first three members in place
  Note notes[NOTES];

  // Or initialize individually with dot operator
  for (int i = 0; i < NOTES; i++){
    notes[i].pitch = 60 + i;
    notes[i].velocity = 127;
    notes[i].channel = 1;
  }

  for (int i = 0; i < NOTES; i++){
    printf("MIDI note properties for index %d is: \n", i);
    printf("Pitch is: %d\n", notes[i].pitch);
    printf("Velocity is: %d\n", notes[i].velocity);
    printf("Channel is: %d\n", notes[i].channel);
    printf("\n");
  }  

  return 0;
}
