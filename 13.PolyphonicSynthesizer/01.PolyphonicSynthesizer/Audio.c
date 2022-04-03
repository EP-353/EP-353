#include "Audio.h"

int initPortAudio(){
  PaError error = Pa_Initialize();
  if(error != paNoError){
    printf("Error: Pa_Initialize() failed with %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // List Audio Devices
  // printPaDevices();

  return 0;
}

int closePortAudio(){
  PaError error = Pa_Terminate();
  if(error != paNoError){
    printf("Error: Pa_Terminate() failed with %s\n",Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}

int openAudioStream(AudioStream *audioStream, PaStreamCallback *streamCallback, void *userData){  
  //Configure port audio output streaming setup
  memset(&audioStream->output, 0, sizeof(PaStreamParameters));
  audioStream->output.channelCount = kNumChannels;
	audioStream->output.device = kAudioOutputDeviceIndex;
	audioStream->output.sampleFormat = paFloat32;
	audioStream->output.suggestedLatency = 0.0;

  //Open port audio streaming
  PaError error = Pa_OpenStream(
    &audioStream->stream,
    NULL, //input
    &audioStream->output, //output
    kSamplingRate,
    kNumFramesPerBuffer, //frames per buffer
    paNoFlag,
    streamCallback,
    userData
  );

  //Check for error in opening port audio streaming
  if(error != paNoError){
    printf("Error: Failed to open port audio stream. %s\n", Pa_GetErrorText(error));
    closePortAudio();
    return 1;
  }

  return 0;
}

int startAudioStream(AudioStream *audioStream){
  //Start port audio streaming
  PaError error = Pa_StartStream(audioStream->stream);
  if(error != paNoError){
    printf("Error: Failed to start port audio stream. %s\n", Pa_GetErrorText(error));
    return 1;
  }
  else {
    printf("Rendering audio... Press enter to stop streaming audio\n");
    getchar();
    error = Pa_StopStream(audioStream->stream);
    if(error != paNoError){
      printf("Error: Failed to stop port audio stream. %s", Pa_GetErrorText(error));
      return 1;
    }
  }
  return 0;
}

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