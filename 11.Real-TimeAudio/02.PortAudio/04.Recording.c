#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>
#include <sndfile.h>

//Compile with:
//clang 04.Recording.c -o 04.Recording -lportaudio -lsndfile
//Run with:
//./04.Recording

//------------------------------------------------------------------------------------
//Constants
#define kOutputFileName "recording.wav" //Make sure the extension is the same as the recording format
#define kDeviceIndex 0 //Built-in input
#define kNumFramesPerBuffer 512
#define kSamplingRate 44100
#define kNumChannels 2
//------------------------------------------------------------------------------------
//Declare user data that holds SNDFILE and SF_INFO
//so that we can use them inside audio render callback
typedef struct SoundFile {
  SNDFILE *file;
  SF_INFO info;
} SoundFile;
//------------------------------------------------------------------------------------
//Function prototypes
int createOutputSndFile(SoundFile *sndFile);
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
	PaStreamParameters inputParameters; //Parameters for output of a stream
  SoundFile sndFile; //Used for audio render callback

  //Create sound file for recording
  createOutputSndFile(&sndFile);
  
  //Initialize port audio
  if(initPortAudio()) return 1;

  //Print available audio devices
  printPaDevices();

  //Configure port audio streaming setup
  memset(&inputParameters, 0, sizeof(PaStreamParameters));
  inputParameters.channelCount = kNumChannels;
	inputParameters.device = kDeviceIndex;
	inputParameters.sampleFormat = paFloat32;
	inputParameters.suggestedLatency = 0.0;

  //Open port audio streaming
  PaError error = Pa_OpenStream(
    &pStream,
    &inputParameters, //input
    NULL, //no output
    kSamplingRate,
    kNumFramesPerBuffer, //frames per buffer
    paNoFlag,
    renderCallback,
    &sndFile
  );

  //Check for error in opening port audio streaming
  if(error != paNoError){
    printf("Error: Failed to open port audio stream. %s\n", Pa_GetErrorText(error));
    closePortAudio();
    return 1;
  }

  //Start port audio streaming
  error = Pa_StartStream(pStream);
  if(error != paNoError){
    printf("Error: Failed to start port audio stream. %s\n", Pa_GetErrorText(error));
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
  count = sf_write_float(file, (float *) input, frameCount * info.channels);

  return 0;
}
//------------------------------------------------------------------------------------
int createOutputSndFile(SoundFile *sndFile){
  //Configure file format for recording 
  memset(&sndFile->info,0,sizeof(SF_INFO));
  sndFile->info.samplerate = kSamplingRate;
	sndFile->info.channels = kNumChannels;
	sndFile->info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

  //Open sound file in write mode
  sndFile->file = sf_open(kOutputFileName, SFM_WRITE, &sndFile->info);
  if(!sndFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kOutputFileName);
		puts(sf_strerror(NULL));
		return 1;
	}
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