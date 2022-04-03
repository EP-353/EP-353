#include "ADSR.h"

void initADSR(ADSR *adsr, float attackTime, float decayTime, float sustainLevel, float releaseTime, float sampleRate){
    adsr->attackTime = attackTime * sampleRate;
    adsr->decayTime = decayTime * sampleRate;
    adsr->sustainLevel = sustainLevel;
    adsr->releaseTime = releaseTime * sampleRate;
    adsr->gate = false;
    adsr->curFrame = 0;     
    adsr->segment = eIdle;
    adsr->level = 0.0f;
}

void resetADSR(ADSR *adsr){
    if(adsr->segment != eAttack){
        adsr->segment = eAttack;
        adsr->curFrame = adsr->attackTime * adsr->level;
    }
}

void getAmp(ADSR *adsr){
    if(!adsr->gate && adsr->segment == eIdle) return;

    switch (adsr->segment)
    {
        case eIdle:
            adsr->curFrame = 0;
            adsr->segment = eAttack;
            adsr->level = 0.0f;
        break;
        case eAttack:
            adsr->level = (1.0f / adsr->attackTime) * adsr->curFrame++;
            if(adsr->level >= 1.0f){
                adsr->segment = eDecay;
                adsr->curFrame = 0;
            }
        break;
        case eDecay:
            adsr->level = ((adsr->sustainLevel - 1.0f) / adsr->decayTime) 
                    * adsr->curFrame++ + 1.0f;
            if(adsr->level <= adsr->sustainLevel){
                adsr->segment = eSustain;
                adsr->curFrame = 0;
            }
        break;
        case eSustain:
            if(adsr->level != adsr->sustainLevel) adsr->level = adsr->sustainLevel;
            if(!adsr->gate){
                adsr->segment = eRelease;
            }
        break;
        case eRelease:
            adsr->level = (-adsr->sustainLevel / adsr->releaseTime) 
                    * adsr->curFrame++ + adsr->sustainLevel;
            if(adsr->level <= 0.0f){
                adsr->segment = eIdle;
                adsr->level = 0.0f;
            }
        break;
    }
}