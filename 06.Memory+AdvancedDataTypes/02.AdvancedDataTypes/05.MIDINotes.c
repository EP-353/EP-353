/*
To compile and run this program, type:
clang 05.MIDINotes.c -o 05.MIDINotes && ./05.MIDINotes
*/

#include <stdio.h>
#include <stdlib.h>

const int NOTES = 10;

int main(void) {
  unsigned char pitches[NOTES];
  unsigned char velocities[NOTES];
  unsigned char channels[NOTES];

  for (int i = 0; i < NOTES; i++){
    pitches[i] = 60 + i;
    velocities[i] = 127;
    channels[i] = 1;
  }
  
  for (int i = 0; i < NOTES; i++){
    printf("MIDI note properties for index %d is: \n", i);
    printf("Pitch is: %d\n", pitches[i]);
    printf("Velocity is: %d\n", velocities[i]);
    printf("Channel is: %d\n", channels[i]);
    printf("\n");
  }  

  return 0;
}