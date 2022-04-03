#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

//Compile with:
//clang 01.Flanger.c -o 01.Flanger -lsndfile
//Run with:
//./01.Flanger

#define kInputFileName "DistortedGuitarStrum.wav"
#define kOutputFileName "Flanger.wav"
#define kDepth 0.002 // Second
#define kOffset 0.002 // Second (Needs to be bigger than or equal to kDepth to avoid negative numbers)
#define kRate 0.5 //Hz

//Hold SNDFILE and SF_INFO together
typedef struct SoundFile {
  SNDFILE *file;
  SF_INFO info;
} SoundFile;

//Function prototypes
int openInputSndFile(SoundFile *inFile);
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process(float *inBuffer, float *outBuffer, sf_count_t bufferSize);

//Global Variables
float gOffset, gDepth;
int gSampleRate;

int main(void){
  SoundFile inFile, outFile;
  
  //Open input file and create output file
  int error = openInputSndFile(&inFile);

  if(error) return 1;

  // Get buffer size
  sf_count_t bufferSize = inFile.info.frames;

  //Allocate buffers for sound processing
  float *inBuffer = (float *) malloc(bufferSize*sizeof(float));
  float *outBuffer = (float *) calloc(bufferSize,sizeof(float));

  //Copy content the file content to the buffer
  sf_read_float(inFile.file, inBuffer, bufferSize);
  
  gOffset = inFile.info.samplerate * kOffset;
  gDepth = inFile.info.samplerate * kDepth;
  gSampleRate = inFile.info.samplerate;

  //process inBuffer and copy the result to outBuffer
  process(inBuffer, outBuffer, bufferSize);
  
  //Create output file and write the result
  error = createOutputSndFile(&inFile, &outFile);
  if(error) return 1;
  sf_write_float(outFile.file, outBuffer, bufferSize);
  
  // //Clean up
  sf_close(inFile.file);
  sf_close(outFile.file);
  free(inBuffer);
  free(outBuffer);
    
  return 0;
}

void process(float *inBuffer, float *outBuffer, sf_count_t bufferSize){
  sf_count_t m; // distance in integer
  float distance, delayPosition, delta;
  
  for(sf_count_t n = 0; n < bufferSize; n++){
    outBuffer[n] = inBuffer[n];
    
    delayPosition = gOffset + gDepth * sin(2.0 * M_PI * kRate * n / gSampleRate);
    distance = (float) n - delayPosition; // Caluclate the distance of delayPosition to n in samples
    m = (int) distance; // Make the distance into integer for indexing
    delta = distance - (float)m; // Get the fractional part of the distance for amplitude control
    
    if (m >= 0 && m + 1 < bufferSize){
      // Mix original signals based on sample distance
      outBuffer[n] += delta * inBuffer[m + 1] + (1.0 - delta) * inBuffer[m]; 
    }
  }
}

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

  //Check if the file is mono
  if(sndFile->info.channels > 1){
    printf("Input file is not mono\n");
    return 1;
  }

  //print out information about opened sound file
  printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
	printf("A number of channels in this file is %d\n", sndFile->info.channels);
  printf("A number of frames in this file is %lld\n", sndFile->info.frames);
  printf("time is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

  return 0;
}

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){
  //Open another sound file in write mode
  outFile->file = sf_open(kOutputFileName, SFM_WRITE, &inFile->info);
  if(!outFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kOutputFileName);
		puts(sf_strerror(NULL));
		return 1;
	}
  return 0;
}