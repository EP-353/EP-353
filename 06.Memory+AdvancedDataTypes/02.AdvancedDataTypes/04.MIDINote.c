/*
To compile and run this program, type:
clang 04.MIDINote.c -o 04.MIDINote && ./04.MIDINote
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned char pitch = 69;
  unsigned char velocity = 127;
  unsigned char channel = 1;

  printf("MIDI note properties: \n");
  printf("Pitch is: %d\n", pitch);
  printf("Velocity is: %d\n", velocity);
  printf("Channel is: %d\n", channel);
}