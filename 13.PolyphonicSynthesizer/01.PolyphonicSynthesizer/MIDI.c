#include "MIDI.h"

// Function Prototypes
int initPortMIDI(MIDIStream *midiStream, bool openInput, bool openOutput){
  //Initialize Port MIDI
  PmError error = Pm_Initialize();
  if(error != pmNoError){
    printf("Error: Pm_Initialize() failed. %s\n", Pm_GetErrorText(error));
    return 1;
  }

  // List MIDI Devices
  // printPmDevices();

  //Open MIDI input
  if(openInput){
    error = Pm_OpenInput(&midiStream->input, kMIDIInputDeviceID, NULL, 512L, NULL, NULL);
    if(error != pmNoError){
      printf("Error: Pm_OpenInput() failed. %s\n", Pm_GetErrorText(error));
      return 1;
    }
  }

  // Clear all inputs to start fresh
  Pm_Read(midiStream->input, midiStream->events, kMaxMIDIEvents);
  
  return 0;
}

int closePortMIDI(MIDIStream *midiStream){
  PmError error;
  //Close input MIDI stream
  if(midiStream->input){
    error = Pm_Close(midiStream->input);
    if(error != pmNoError){
      printf("Error: Pm_Close() failed. %s\n", Pm_GetErrorText(error));
      return 1;
    }
  }
  
  //Terminate Port MIDI
  error = Pm_Terminate();
  if(error != pmNoError){
    printf("Error: Pm_Terminate() failed. %s\n", Pm_GetErrorText(error));
    return 1;
  }
  return 0;
}

void printPmDevices(){
  //Get the number of port MIDI devices available
  int numDevices = Pm_CountDevices();
  PmDeviceID curDeviceID; //current device ID
  const PmDeviceInfo *pDeviceInfo; //Provides information and capabilities of PortMIDI devices

  //Iterate over each device and print out information about them
  for(curDeviceID = 0; curDeviceID < numDevices; curDeviceID++){
    pDeviceInfo = Pm_GetDeviceInfo(curDeviceID);
    printf("--------------------------------------------\n");
    printf("ID: %d, Name: %s, ",curDeviceID,pDeviceInfo->name);
    printf("MIDI API: %s\n",pDeviceInfo->interf);
    printf("Max MIDI outputs: %d\t",pDeviceInfo->output);
    printf("Max MIDI inputs: %d\n\n",pDeviceInfo->input);
  }
}