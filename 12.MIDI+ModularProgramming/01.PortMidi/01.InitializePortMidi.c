#include <stdio.h>
#include <portmidi.h>

//Compile with:
//clang 01.InitializePortMidi.c -o 01.InitializePortMidi -lportmidi
//Run with:
//./01.InitializePortMidi

int main(void){
  PmError error; //Store error codes returned by PortMIDI functions

  //Initialize Port MIDI
  error = Pm_Initialize();
  if(error != pmNoError){
    printf("Error: Pm_Initialize() failed with %s\n", Pm_GetErrorText(error));
    return 1;
  }

  //Terminate Port MIDI
  error = Pm_Terminate();
  if(error != pmNoError){
    printf("Error: Pm_Terminate() failed with %s\n",Pm_GetErrorText(error));
    return 1;
  }
}