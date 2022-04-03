/* A program that shows example usage of structure.

To compile and run this program, type:
clang 06.MIDINoteStructure.c -o 06.MIDINoteStructure && ./06.MIDINoteStructure
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

int main() {
  //Define a variable note of type Note, and initialize its first three members in place
  Note note = {69, 127, 1};

  // Or initialize individually with dot operator
  note.pitch = 69;
  note.velocity = 127;
  note.channel = 1;

  // Access individual elements in struct with dot operator
  printf("MIDI note properties: \n");
  printf("Pitch is: %d\n", note.pitch);
  printf("Velocity is: %d\n", note.velocity);
  printf("Channel is: %d\n", note.channel);

  return 0;
}
