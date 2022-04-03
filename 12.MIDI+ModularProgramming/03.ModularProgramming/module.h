// #pragma once asks the compiler to include a header file only a single time, 
// no matter how many times it has been imported:
#pragma once

#include <math.h>

//Global variable accessible by other source files
extern float gBaseFreq;

//Function prototypes
float midi2freq(char midi);
char freq2midi(float freq);