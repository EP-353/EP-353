#include "Interpolate.h"

void initInterpolate(Interpolate *interpolate, float time, float sampleRate) {
    interpolate->start = 0;
    interpolate->value = 0;
    interpolate->target = 0;
    interpolate->curFrame = 0;
    interpolate->time = time * sampleRate;
    interpolate->isInterpolating = false;
}

void setTarget(Interpolate *interpolate, float target){
    interpolate->start = interpolate->target;
    interpolate->target = target;
    interpolate->isInterpolating = true;
    interpolate->curFrame = 0;
}

void getNextValue(Interpolate *interpolate){
    if(!interpolate->isInterpolating) return;

    interpolate->value = interpolate->start + (interpolate->target - interpolate->start) * interpolate->curFrame++ / interpolate->time;
    
    if(interpolate->curFrame >= interpolate->time) {
        interpolate->isInterpolating = false;
    }
}