#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <portmidi.h>

#define kMIDIInputDeviceID 0
#define kMaxMIDIEvents 32

typedef struct MIDIStream {
  int numMIDIEvents; //Store a count for all incoming MIDI events
  PmEvent events[kMaxMIDIEvents]; //Hold individual MIDI events
  PortMidiStream *input; //a descriptor for an open MIDI input device
} MIDIStream;

typedef struct MIDIEvent {
  char note;
  char velocity;
  bool isOn;
} MIDIEvent;

// Function Prototypes
int initPortMIDI(MIDIStream *midiStream, bool openInput, bool openOutput);
int closePortMIDI(MIDIStream *midiStream);
void printPmDevices();