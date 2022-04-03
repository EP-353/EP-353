#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>

//Compile with:
//clang 02.AudioDeviceList.c -o 02.AudioDeviceList -lportaudio
//Run with:
//./02.AudioDeviceList

int main(void){
  PaError error; //Store error codes returned by PortAudio functions
  
  //Initialize Port Audio
  error = Pa_Initialize();
  if(error != paNoError){
    printf("Error: Pa_Initialize() failed with %s\n", Pa_GetErrorText(error));
    return 1;
  }

  PaDeviceIndex numDevices; //Store the number of device available
  PaDeviceIndex curDeviceID; //current device ID

  const PaDeviceInfo *pDeviceInfo; //Provides information and capabilities of PortAudio devices
  const PaHostApiInfo *pHostApiInfo; //Provides information about a particular host API

  //Get number of port audio devices available
  numDevices = Pa_GetDeviceCount();

  //Iterate over each device and print out information about them
  for(curDeviceID = 0; curDeviceID < numDevices; curDeviceID++){
    pDeviceInfo = Pa_GetDeviceInfo(curDeviceID);
    pHostApiInfo = Pa_GetHostApiInfo(pDeviceInfo->hostApi);
    printf("--------------------------------------------\n");
    printf("ID: %d, Name: %s, ",curDeviceID,pDeviceInfo->name);
    printf("API name: %s\n",pHostApiInfo->name);
    printf("Max output channels: %d,\t",pDeviceInfo->maxOutputChannels);
    printf("Max input channels: %d\n\n",pDeviceInfo->maxInputChannels);
  }

  //Terminate Port Audio
  error = Pa_Terminate();
  if(error != paNoError){
    printf("Error: Pa_Terminate() failed with %s\n",Pa_GetErrorText(error));
    return 1;
  }
}