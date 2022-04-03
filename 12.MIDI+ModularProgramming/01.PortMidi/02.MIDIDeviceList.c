#include <stdio.h>
#include <portmidi.h>

//Compile with:
//clang MIDIDeviceList.c -o MIDIDeviceList -lportmidi
//Run with:
//./MIDIDeviceList

int main(void){
  PmError error; //Store error codes returned by PortMIDI functions
  int numDevices; //Store the number of MIDI device available
  PmDeviceID curDeviceID; //current device ID

  const PmDeviceInfo *pDeviceInfo; //Provides information and capabilities of PortMIDI devices

  //Initialize Port MIDI
  error = Pm_Initialize();
  if(error != pmNoError){
    printf("Error: Pm_Initialize() failed with %s\n", Pm_GetErrorText(error));
    return 1;
  }

  //Get the number of port MIDI devices available
  numDevices = Pm_CountDevices();

  //Iterate over each device and print out information about them
  for(curDeviceID = 0; curDeviceID < numDevices; curDeviceID++){
    pDeviceInfo = Pm_GetDeviceInfo(curDeviceID);
    printf("--------------------------------------------\n");
    printf("ID: %d, Name: %s, ",curDeviceID,pDeviceInfo->name);
    printf("MIDI API: %s\n",pDeviceInfo->interf);
    printf("Max MIDI outputs: %d\t",pDeviceInfo->output);
    printf("Max MIDI inputs: %d\n\n",pDeviceInfo->input);
  }

  //Terminate Port MIDI
  error = Pm_Terminate();
  if(error != pmNoError){
    printf("Error: Pm_Terminate() failed with %s\n",Pm_GetErrorText(error));
    return 1;
  }
}