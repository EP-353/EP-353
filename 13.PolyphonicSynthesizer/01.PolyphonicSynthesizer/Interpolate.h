#pragma once

#include <stdbool.h>

typedef struct Interpolate {
    float start;
    float value;
    float target;
    long curFrame;
    float time;
    bool isInterpolating;
} Interpolate;

void initInterpolate(Interpolate *interpolate, float time, float sampleRate);
void setTarget(Interpolate *interpoloate, float target);
void getNextValue(Interpolate *interpolate);
