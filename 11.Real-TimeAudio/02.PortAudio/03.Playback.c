#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>
#include <sndfile.h>

//Compile with:
//clang 03.Playback.c -o 03.Playback -lportaudio -lsndfile
//Run with:
//./03.Playback

//------------------------------------------------------------------------------------
//Constants
#define kInputFileName "12STRG40MIC.aif"
#define kDeviceIndex 1 //Built-in Output
#define kNumFramesPerBuffer 512
//------------------------------------------------------------------------------------
//Declare user data that holds SNDFILE and SF_INFO
//so that we can use them inside audio render callback
typedef struct SoundFile {
  SNDFILE *file;
  SF_INFO info;
} SoundFile;
//------------------------------------------------------------------------------------
//Function prototypes
int openInputSndFile(SoundFile *sndFile);
int initPortAudio();
int closePortAudio();
void printPaDevices();
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
int main(){
  PaStream *pStream = NULL; //For port audio streaming
	PaStreamParameters outputParameters; //Parameters for output of a stream
  SoundFile sndFile; //Used for audio render callback

  //Open sound file for a playback
  openInputSndFile(&sndFile);
  
  //Initialize port audio
  if(initPortAudio()) return 1;

  //Print available audio devices
  printPaDevices();

  //Configure port audio streaming setup
  memset(&outputParameters, 0, sizeof(PaStreamParameters));
  outputParameters.channelCount = sndFile.info.channels;
	outputParameters.device = kDeviceIndex;
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = 0.0;

  //Open port audio streaming
  PaError error = Pa_OpenStream(
    &pStream,
    NULL, //no input
    &outputParameters, //output
    sndFile.info.samplerate,
    kNumFramesPerBuffer, //frames per buffer
    paNoFlag,
    renderCallback,
    &sndFile //User data
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

  //Clean up
  sf_close(sndFile.file);

  return 0;
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
  //Convert user data so that we can use it in the callback
  SoundFile *sndFile = (SoundFile *) userData;
  SNDFILE *file = sndFile->file;
  SF_INFO info = sndFile->info;
  sf_count_t count;

  //Copy file content to output buffer frame count at a time
  count = sf_read_float(file, (float *) output, frameCount * info.channels);

  //Loop
  if(count != frameCount * info.channels){
    sf_count_t leftOver = frameCount * info.channels - count;
    memset(output + leftOver, 0, leftOver * sizeof(float));
    sf_seek(file, 0, SEEK_SET);
  }

  return 0;
}
//------------------------------------------------------------------------------------
int openInputSndFile(SoundFile *sndFile){
  //Initialize SF_INFO with 0s (Required for reading)
  memset(&sndFile->info, 0, sizeof(SF_INFO));

  //Open the original sound file as read mode
  sndFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);
  if(!sndFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kInputFileName);
		puts(sf_strerror(NULL));
		return 1;
  }

  //Check if the file format is in good shape
  if(!sf_format_check(&sndFile->info)){	
    sf_close(sndFile->file);
		printf("Invalid encoding\n");
		return 1;
	}

  //print out information about opened sound file
  printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
	printf("A number of channels in this file is %d\n", sndFile->info.channels);
  printf("A number of frames in this file is %lld\n", sndFile->info.frames);
  printf("Duration is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

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