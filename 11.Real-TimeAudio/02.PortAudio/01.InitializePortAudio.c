#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>

//Compile with:
//clang 01.InitializePortAudio.c -o 01.InitializePortAudio -lportaudio
//Run with:
//./01.InitializePortAudio

int main(void){
  PaError error; //Store error codes returned by PortAudio functions
  
  //Initialize Port Audio
  error = Pa_Initialize();
  if(error != paNoError){
    printf("Error: Pa_Initialize() failed with %s\n", Pa_GetErrorText(error));
    return 1;
  }

  printf("PortAudio error: %s\n", Pa_GetErrorText(error));

  //Terminate Port Audio
  error = Pa_Terminate();
  if(error != paNoError){
    printf("Error: Pa_Terminate() failed with %s\n",Pa_GetErrorText(error));
    return 1;
  }
}