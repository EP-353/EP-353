#include "Wavetable.h"

void createWavetable(Wavetable *wavetable){
  memset(wavetable->table, 0, kTableSize * sizeof(float));
  //Square wave approximation
  for(int i = 1; i <= 15; i+=2){ //Up to 15th harmonics, but only odd harmonics
    double delta = (2.0 * M_PI) / (wavetable->size) * i;
    double angle = 0.0;
    for (int n = 0; n < wavetable->size; n++){
      wavetable->table[n] += (1.0f / i) * sin(angle);
      angle += delta;
    }
  }
}

void initWavetable(Wavetable *wavetable){
  wavetable->size = kTableSize;
  wavetable->delta = kDefaultFrequency * (kTableSize / kSamplingRate);//set frequecy
  wavetable->curIndex = 0.0f;
  wavetable->isPlaying = true;  
  initInterpolate(&wavetable->amplitude, 0.02, kSamplingRate);
  createWavetable(wavetable);
}

float next(Wavetable *wavetable){
  unsigned long index0 = (unsigned long) wavetable->curIndex;
  unsigned long index1 = index0 + 1;
  
  //Make sure that the index1 does not exceed the size of the wavetable
  if(index1 >= wavetable->size){
    index1 -= wavetable->size;
  }

  //Calculate the interpolation value
  float fraction = wavetable->curIndex - (float) index0;
  
  //get values from the wavetable
  float value0 = wavetable->table[index0];
  float value1 = wavetable->table[index1];
  
  //Calculate the interpolated value
  float sample = value0 + fraction * (value1 - value0);
  
  //increment the angle delta of the table and wrap
  wavetable->curIndex += wavetable->delta;
  if(wavetable->curIndex >= (float) wavetable->size){
      wavetable->curIndex -= (float) wavetable->size;
  }
  
  getNextValue(&wavetable->amplitude);
  return sample * wavetable->amplitude.value;
}

void setFrequency(Wavetable *wavetable, char midi){
    float frequency = (440.0f * pow(2, (midi - 69.0f)/12.0f));
    wavetable->delta = frequency * (kTableSize / kSamplingRate);
}

void setAmplitude(Wavetable *wavetable, float amplitude){
  setTarget(&wavetable->amplitude, amplitude);
}