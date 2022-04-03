/* A program that shows example usage of nested structures.

To compile and run this program, type:
clang 08.Strcutre+Pointer.c -o 08.Strcutre+Pointer && ./08.Strcutre+Pointer
*/

#include <stdio.h>
#include <stdlib.h>

struct Note {
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
}; //Semi-column at the end

//Let's typedef to avoid typing 'struct' again.
typedef struct Note Note;

int main() {
  Note *note = (Note *) malloc(sizeof(Note));

  // Check for null pointer
  if (note == NULL) {
    fprintf(stderr, "malloc failed\n");
    return -1;
  }

  // Accessing pointer-based structure 
  // must be done with arrow (->) operator
  note->pitch = 69;
  note->velocity = 127;
  note->channel = 1;
  
  printf("MIDI note properties: \n");
  printf("Pitch is: %d\n", note->pitch);
  printf("Velocity is: %d\n", note->velocity);
  printf("Channel is: %d\n", note->channel);

  //Free the memory space
  free(note);

  return 0;
}
