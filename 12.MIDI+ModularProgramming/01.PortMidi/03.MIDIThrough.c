#include <stdio.h>
#include <portmidi.h>

//Compile with:
//clang 01.MIDIThrough.c -o 01.MIDIThrough -lportmidi
//Run with:
//./01.MIDIThrough

//------------------------------------------------------------------------------------
// Constants
#define kMIDIInputDeviceID 1
#define kMIDIOutputDeviceID 2
#define kMaxMIDIEvents 32
//------------------------------------------------------------------------------------
// Function prototypes
int initPortMidi();
int closePortMidi();
void printPmDevices();

int main(void){
  int numMIDIEvents = 0; //Store a count for all incoming MIDI events
  PmEvent midiEvents[kMaxMIDIEvents]; //Hold individual MIDI events
  PortMidiStream *inputStream; //a descriptor for an open MIDI input device
  PortMidiStream *outputStream; //a descriptor for an open MIDI output device
  
  //Initialize Port MIDI
  if(initPortMidi()) return 1;

  //Print available midi devices
  printPmDevices();

  //Open MIDI input
  PmError error = Pm_OpenInput(&inputStream, kMIDIInputDeviceID, NULL, 512L, NULL, NULL);
  if(error != pmNoError){
    printf("Error: Pm_OpenInput() failed. %s\n", Pm_GetErrorText(error));
    return 1;
  }

  //Open MIDI output
  error = Pm_OpenOutput(&outputStream, kMIDIOutputDeviceID, NULL, 512L, NULL, NULL,0);
  if(error != pmNoError){
    printf("Error: Pm_OpenOutput() failed. %s\n", Pm_GetErrorText(error));
    return 1;
  }

  //Continously run the MIDI stream until we provide a note number bigger than 100
  unsigned char note = 0;
  while(note < 100){
    if(Pm_Poll(inputStream)){
      numMIDIEvents = Pm_Read(inputStream, midiEvents, kMaxMIDIEvents);
      for(int i=0; i < numMIDIEvents;i++){
        // Comment printf() out for a faster response
        printf("status: 0x%x, byte1: %d, byte2: %d, time: %.3f\n",
          Pm_MessageStatus(midiEvents[i].message),//MIDI status
          Pm_MessageData1(midiEvents[i].message),//Byte Data 1
          Pm_MessageData2(midiEvents[i].message),//Byte Data 2
          midiEvents[i].timestamp/1000.);

          Pm_WriteShort(outputStream, 0, Pm_Message(
            Pm_MessageStatus(midiEvents[i].message),
            Pm_MessageData1(midiEvents[i].message),
            Pm_MessageData2(midiEvents[i].message)
          ));

          // Look for Note on message with note number >= 100
          if (Pm_MessageStatus(midiEvents[i].message) == 0x90 
            && Pm_MessageData1(midiEvents[i].message) >= 100){
              note = Pm_MessageData1(midiEvents[i].message);
              break;
          }
      }
    }
  }

  //Close input MIDI stream
  error = Pm_Close(inputStream);
  if(error != pmNoError){
    printf("Error: Pm_Close() failed. %s\n",Pm_GetErrorText(error));
    return 1;
  }

  //Close output MIDI stream
  error = Pm_Close(outputStream);
  if(error != pmNoError){
    printf("Error: Pm_Close() failed. %s\n",Pm_GetErrorText(error));
    return 1;
  }

  //Close Port MIDI
  if(closePortMidi()) return 1;

  return 0;
}

int initPortMidi() { //Initialize Port MIDI
  PmError error = Pm_Initialize();
  if(error != pmNoError){
    printf("Error: Pm_Initialize() failed. %s\n", Pm_GetErrorText(error));
    return 1;
  }
  return 0;
}

int closePortMidi() { //Terminate Port MIDI
  PmError error = Pm_Terminate();
  if(error != pmNoError){
    printf("Error: Pm_Terminate() failed. %s\n",Pm_GetErrorText(error));
    return 1;
  }
  return 0;
}

void printPmDevices() {
  //Get the number of port MIDI devices available
  int numDevices = Pm_CountDevices(); 
  PmDeviceID curDeviceID;
  const PmDeviceInfo *pDeviceInfo; 
  
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