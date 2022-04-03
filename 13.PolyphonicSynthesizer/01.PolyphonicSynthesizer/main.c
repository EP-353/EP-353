#include "MIDI.h"
#include "Audio.h"
#include "Synth.h"
//Compile with:
//make
//Run with:
//make run

#define kMIDIAmpIncrement 0.007874016f
#define kNumVoices 10

void getMIDIInput(Synth *synth);
void process(float *buffer, unsigned long numFrames, Synth *synth);

int main(void){
  //Initlaize MIDI stream
  MIDIStream midiStream;
  if(initPortMIDI(&midiStream, true, false)) return 1;

  //Initialize synthesizers
  Synth synths[kNumVoices];
  for (int i = 0; i < kNumVoices; i++){
    if(initSynth(&synths[i])) return 1;
    synths[i].midiStream = &midiStream;
  }

  //Initialize audio stream
  AudioStream audioStream;
  if(initPortAudio()) return 1;
  
  // Open audio stream
  if(openAudioStream(&audioStream, renderCallback, &synths)) return 1;

  // Start audio processing
  if(startAudioStream(&audioStream)) return 1;
  
  // End audio processing
  if(closePortAudio()) return 1;
  
  //Close MIDI stream
  if(closePortMIDI(&midiStream)) return 1;

  return 0;
}

int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData 
){
  float *inBuffer = (float *) input;
  float *outBuffer = (float *) output;
  unsigned long numFrames = frameCount * kNumChannels;
  Synth *synths = (Synth *) userData;

  getMIDIInput(synths);
  memset(outBuffer, 0, sizeof(float) * numFrames);
  process(outBuffer, numFrames, synths);    

  return 0;
}

void process(float *buffer, unsigned long numFrames, Synth *synths){
  static float sample = 0;
  for (int voice = 0; voice < kNumVoices; voice++){
    for(unsigned long n = 0; n < numFrames; n += kNumChannels){
      getAmp(&synths[voice].adsr);
      sample = next(&synths[voice].wavetable) * synths[voice].adsr.level;
      for(int c = 0; c < kNumChannels; c++){
        buffer[n + c] += sample;
      }
    }
  }
}

void getMIDIInput(Synth *synths){
  static int numMIDIEvents;
  static unsigned char velocity;
  static unsigned char note;
  static unsigned char status;
  MIDIStream midiStream = *synths[0].midiStream;
  
  if(Pm_Poll(midiStream.input)){
    numMIDIEvents = Pm_Read(midiStream.input, midiStream.events, kMaxMIDIEvents);
    for(int i = 0; i < numMIDIEvents; i++){
      status = Pm_MessageStatus(midiStream.events[i].message);

      if(status >= 0x90 && status <= 0x9f){ // Note On Messages
        note = Pm_MessageData1(midiStream.events[i].message);
        velocity = Pm_MessageData2(midiStream.events[i].message);

        for (int voice = 0; voice < kNumVoices; voice++){
          if(!synths[voice].isPlaying){
            synths[voice].midiEvent.note = note;
            synths[voice].midiEvent.velocity = velocity;

            //Set frequency & amp
            setFrequency(&synths[voice].wavetable, synths[voice].midiEvent.note);
            setAmplitude(&synths[voice].wavetable, synths[voice].midiEvent.velocity * kMIDIAmpIncrement);

            // Retrigger adsr if it is still on or in the release state
            if(synths[voice].adsr.gate || synths[voice].adsr.segment == eRelease) {
              resetADSR(&synths[voice].adsr);  
            }

            synths[voice].adsr.gate = true;
            synths[voice].isPlaying = true;
            break;
          }
        }
      }
      else if(status >= 0x80 && status <= 0x8f){ // Note Off Messages
        note = Pm_MessageData1(midiStream.events[i].message);
        for (int voice = 0; voice < kNumVoices; voice++){
          if(synths[voice].isPlaying && synths[voice].midiEvent.note == note){
            synths[voice].adsr.gate = false;
            synths[voice].isPlaying = false;
            break;
          }
        }
      }
    }
  }
}
