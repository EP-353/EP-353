#pragma once

#include <stdio.h>
#include <stdbool.h>

#define kAttackTime 0.01
#define kDecayTime 0.1
#define kSustainLevel 0.7
#define kReleaseTime 0.4

typedef enum ADSRSegement {
    eIdle, eAttack, eDecay, eSustain, eRelease
} ADSRSegement;

typedef struct ADSR {
  bool gate;
  float level;
  float attackTime;
  float decayTime;
  float sustainLevel;
  float releaseTime;
  long curFrame;
  ADSRSegement segment;
} ADSR;

// Function Prototypes
void initADSR(ADSR *adsr, float attackTime, float decayTime, float sustainLevel, float releaseTime, float sampleRate);
void resetADSR(ADSR *adsr);
void getAmp(ADSR *adsr);