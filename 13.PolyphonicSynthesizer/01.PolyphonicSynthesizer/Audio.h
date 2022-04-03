#pragma once

#include <stdio.h>
#include <string.h>
#include <portaudio.h>

#define kAudioOutputDeviceIndex 1 //Built-in Output
#define kNumFramesPerBuffer 512
#define kSamplingRate 44100.0
#define kNumChannels 2

typedef struct AudioStream {
  PaStream *stream; //For port audio streaming
  PaStreamParameters input; //Parameters for output of a stream
	PaStreamParameters output; //Parameters for output of a stream
} AudioStream;

//Audio render callback function
int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData 
);

//Function Prototypes
int initPortAudio();
int closePortAudio();
int openAudioStream(AudioStream *audioStream, PaStreamCallback *streamCallback, void *userData);
int startAudioStream(AudioStream *audioStream);
void printPaDevices();