#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//Excute this code using:
//clang 01.SineWave.c -o 01.SineWave -lsndfile; ./01.SineWave

#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "SineWave.wav"

int main(void){
  SNDFILE *sndFile;
  SF_INFO sfInfo;
  double *buffer;

  //Sound parameters
  double amplitude = 0.25;
  double frequency = 250.0;

  //Create kNumChannels worth buffer for holding audio data 
  buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
  if (!buffer){
    printf ("Error : Malloc failed.\n");
		return 1;
	};

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfo, 0, sizeof(SF_INFO)); 

  //Set the format for the sound file to be saved
  sfInfo.samplerate = kSampleRate;
	sfInfo.frames = kNumFrames;
	sfInfo.channels = kNumChannels;
	sfInfo.format = kFormat;

   //Open the original sound file as read mode
  sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
  if(!sndFile){
    printf ("Error : could not open file : %s\n", kFileName);
		puts(sf_strerror (NULL));
		return 1;
  }
  
  //Compute sine wave (interleave channels)
  for (int t = 0; t < kNumFrames; t++){
    // Compute A sin(2πft+φ). Phase is ignored in this case.
    // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
    double sample = amplitude * sin(2.0 * M_PI * (frequency/kSampleRate) * t);
    // Write the same sample into all channels
    for(int c = 0; c < kNumChannels; c++){
      buffer[kNumChannels * t + c] = sample;
    }
  }
  
  //Write out the result
  sf_count_t count = sf_write_double(sndFile, buffer, sfInfo.channels * kNumFrames);

  //Make sure writing the file succeeeded  
  if(count != sfInfo.channels * kNumFrames){
    puts(sf_strerror(sndFile));
  }

  //Close sound file and buffer
  sf_close(sndFile);
  free(buffer);

  return 0;
}