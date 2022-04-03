#pragma once

#include "MIDI.h"
#include "Wavetable.h"
#include "ADSR.h"

#define kNoteDuration 1

typedef struct Synth {
  Wavetable wavetable;
  ADSR adsr;
  MIDIStream *midiStream;
  MIDIEvent midiEvent;
  bool isPlaying;
} Synth;

// Function Prototypes
int initSynth(Synth *synth);