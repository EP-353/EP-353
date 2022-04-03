#pragma once

#include <memory.h>
#include <stdbool.h>
#include <math.h>
#include "Audio.h"
#include "Interpolate.h"

#define kDefaultFrequency 440.0
#define kTableSize (1<<7) //128

typedef struct Wavetable {
  float table[kTableSize];
  unsigned long size;
  float curIndex;
  float delta;
  bool isPlaying;
  Interpolate amplitude;
} Wavetable;

// Function Prototypes
void createWavetable(Wavetable *wavetable);
void initWavetable(Wavetable *wavetable);
float next(Wavetable *wavetable);
void setFrequency(Wavetable *wavetable, char midi);
void setAmplitude(Wavetable *wavetable, float amplitude);