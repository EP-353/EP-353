#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>
#include <portaudio.h>

//Compile with:
//clang 04.Delay.c -o 04.Delay -lportaudio
//Run with:
//./04.Delay
//------------------------------------------------------------------------------------
//Constants
#define kInputDeviceIndex 0 //Built-in input
#define kOutputDeviceIndex 1 //Built-in output
#define kNumFramesPerBuffer 512
#define kSamplingRate 44100.0
#define kNumChannels 2
#define kMaxDelayLength ((unsigned long) kSamplingRate * 2)
//------------------------------------------------------------------------------------
//Struct for delay
typedef struct Delay {
  float *buffer;
  unsigned long size;
  unsigned long readPosition;
  unsigned long writePosition;
  float time;
  float feedback;
  float dryWet;
} Delay;
//------------------------------------------------------------------------------------
//Function prototypes
int initPortAudio();
int closePortAudio();
void printPaDevices();
void process(float *buffer, unsigned long numFrames, void *userData);
//------------------------------------------------------------------------------------
//Audio render callback function
int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData 
);
//------------------------------------------------------------------------------------
int main(int argc, char *argv[]){
  PaStream *pStream = NULL; //For port audio streaming
	PaStreamParameters inputParameters; //Parameters for input of a stream
  PaStreamParameters outputParameters; //Parameters for output of a stream

  //Set up delay
  Delay delay;
  delay.buffer = (float *) calloc(kMaxDelayLength, sizeof(float *)); //set everything to zero to avoid noise at the beginning
  delay.time = 0.25;
  delay.feedback = 0.5;
  delay.dryWet = 0.5;
  delay.writePosition = 0;
  //Keep the read position before write position for the amount of delay time
  delay.readPosition = ((unsigned long) (delay.writePosition - (delay.time * kSamplingRate) + kMaxDelayLength)) % kMaxDelayLength;

  //Initialize port audio
  if(initPortAudio()) return 1;

  //Print available audio devices
  printPaDevices();

  //Configure port audio input streaming setup
  memset(&inputParameters, 0, sizeof(PaStreamParameters));
  inputParameters.channelCount = kNumChannels;
	inputParameters.device = kInputDeviceIndex;
	inputParameters.sampleFormat = paFloat32;
	inputParameters.suggestedLatency = 0.0;
  
  //Configure port audio output streaming setup
  memset(&outputParameters, 0, sizeof(PaStreamParameters));
  outputParameters.channelCount = kNumChannels;
	outputParameters.device = kOutputDeviceIndex;
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = 0.0;

  //Open port audio streaming
  PaError error = Pa_OpenStream(
    &pStream,
    &inputParameters, //input
    &outputParameters, //output
    kSamplingRate,
    kNumFramesPerBuffer, //frames per buffer
    paNoFlag,
    renderCallback,
    &delay
  );

  //Check for error in opening port audio streaming
  if(error != paNoError){
    printf("Error: Failed to open port audio stream. %s\n",Pa_GetErrorText(error));
    closePortAudio();
    return 1;
  }

  //Start port audio streaming
  error = Pa_StartStream(pStream);
  if(error != paNoError){
    printf("Error: Failed to start port audio stream. %s\n",Pa_GetErrorText(error));
  }
  else {
    printf("Rendering audio... Press enter to stop streaming audio\n");
    getchar();
    error = Pa_StopStream(pStream);
    if(error != paNoError){
      printf("Error: Failed to stop port audio stream. %s", Pa_GetErrorText(error));
    }
  }

  //Close port audio streaming
  if(closePortAudio()) return 1;

  //Free memory
  free(delay.buffer);

  return 0;
}
//------------------------------------------------------------------------------------
void process(float *buffer, unsigned long numFrames, void *userData){
  Delay *delay = (Delay *) userData;
  int dr = delay->readPosition;
  int dw = delay->writePosition;

  for(unsigned long n = 0; n < numFrames; n += kNumChannels){
    for(int c=0; c < kNumChannels; c++){
      const float in = buffer[n+c];
      //Calculate the output based on incoming microphone, delay buffer, and dry wet mix
      float out = ((1.0f - delay->dryWet) * in + delay->dryWet * delay->buffer[dr]);
      //Write the incoming microphone and delay signal at reading point with feedback amount
      delay->buffer[dw] = in + (delay->buffer[dr] * delay->feedback);

      //Reset index position for reading and writing to zero
      if(++dr >= kMaxDelayLength) dr = 0;
      if(++dw >= kMaxDelayLength) dw = 0;

      //Write the result for speaker output
      buffer[n+c] = out;
    }
  }

  delay->readPosition = dr;
  delay->writePosition = dw;
}
//------------------------------------------------------------------------------------
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

  //Samples are interleaved so increment by two with kNumChannels
  for(unsigned long n=0; n < numFrames; n += kNumChannels){//iterate over samples in channels
    for(int c=0; c < kNumChannels; c++){//Iterate over number of channels
      outBuffer[n+c] = inBuffer[n+c]; //Copy input to output
    }
  }

  process(outBuffer, numFrames, userData);

  return 0;
}
//------------------------------------------------------------------------------------
int initPortAudio(){ //Initialize Port Audio
  PaError error = Pa_Initialize();
  if(error != paNoError){
    printf("Error: Pa_Initialize() failed with %s\n", Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------------
int closePortAudio(){ //Terminate Port Audio
  PaError error = Pa_Terminate();
  if(error != paNoError){
    printf("Error: Pa_Terminate() failed with %s\n",Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------------
void printPaDevices(){
  //Get number of port audio devices available
  PaDeviceIndex numDevices = Pa_GetDeviceCount(); 
  PaDeviceIndex curDeviceID;

  const PaDeviceInfo *pDeviceInfo; 
  const PaHostApiInfo *pHostApiInfo;

  //Iterate over each device and print out information about them
  for(curDeviceID = 0; curDeviceID < numDevices; curDeviceID++){
    pDeviceInfo = Pa_GetDeviceInfo(curDeviceID);
    pHostApiInfo = Pa_GetHostApiInfo(pDeviceInfo->hostApi);
    printf("--------------------------------------------\n");
    printf("ID: %d, Name: %s, ", curDeviceID, pDeviceInfo->name);
    printf("API name: %s\n", pHostApiInfo->name);
    printf("Max output channels: %d\t", pDeviceInfo->maxOutputChannels);
    printf("Max input channels: %d\n\n", pDeviceInfo->maxInputChannels);
  }
}