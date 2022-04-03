#include "module.h"

float gBaseFreq = 440.0f;

float midi2freq(char midi){
  return (gBaseFreq * pow(2, (midi - 69)/12.0f));
}

char freq2midi(float freq){
  return 69 + 12.0f * log2(freq/gBaseFreq);
}
