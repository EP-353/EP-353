#include "Synth.h"

int initSynth(Synth *synth){  
  synth->isPlaying = false;
  initWavetable(&synth->wavetable);
  initADSR(&synth->adsr, kAttackTime, kDecayTime, kSustainLevel, kReleaseTime, kSamplingRate);
  return 0;
}