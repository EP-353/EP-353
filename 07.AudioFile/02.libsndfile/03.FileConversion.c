#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h> 

//Compile and run this code using:
//clang 03.FileConversion.c -o FileConversion -lsndfile; ./FileConversion

int main() {
  SNDFILE *inFile = NULL, *outFile = NULL; //pointers to sound files
  SF_INFO sfInfoIn, sfInfoOut; //hold an information about sound files
  float *buffer; //Buffer for holding samples

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfoIn, 0, sizeof(SF_INFO));
  memset(&sfInfoOut, 0, sizeof(SF_INFO));

  //Open the original sound file as read mode
  inFile = sf_open("sine.wav", SFM_READ, &sfInfoIn);
  if(!inFile){
    printf ("Error : could not open file : sine.wav\n");
    puts (sf_strerror (NULL));
    return 1;
  }
  
  //Check if the file format is in good shape
  if(!sf_format_check(&sfInfoIn)){	
    sf_close(inFile);
    printf("Invalid encoding\n");
    return 1;
  }

  //Allocate enough memory space to hold all samples from the input file
  buffer = (float *) malloc(sfInfoIn.frames * sizeof(float));

  //Copy samples from the original file to the new file
  sf_count_t readcount = sf_read_float(inFile, buffer, sfInfoIn.frames);
  printf("Sample count: %lld\nSamples read: %lld\n", sfInfoIn.frames, readcount);

  //Convert to AIFF file and retain information about sample rate, 
  //channels, bit depth, and encoding
  sfInfoOut.samplerate = sfInfoIn.samplerate;
  sfInfoOut.channels = sfInfoIn.channels;
  sfInfoOut.format = SF_FORMAT_AIFF | (sfInfoIn.format & SF_FORMAT_SUBMASK);
  
  //Open another sound file in write mode
  outFile = sf_open("sine.aiff", SFM_WRITE, &sfInfoOut);

  //Check if the file was succefully opened
  if(!outFile){	
    printf ("Error : could not open file : CopiedSine.wav");
    puts (sf_strerror(NULL));
    return 1;
  }

  //Copy samples from the original file to the new file
  sf_write_float(outFile, buffer, readcount);
  
  //Close the open files
  sf_close(inFile);
  sf_close( outFile);

  return 0;
}
