#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h> 

//Compile and run this code using:
//clang 04.Combine.c -o Combine -lsndfile; ./Combine

int main() {
  SNDFILE *inFile1 = NULL, *inFile2 = NULL, *outFile = NULL; //pointers to sound files
  SF_INFO sfInfoIn1, sfInfoIn2, sfInfoOut; //hold an information about sound files
  float *buffer; //Buffer for holding samples

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfoIn1, 0, sizeof(SF_INFO));
  memset(&sfInfoIn2, 0, sizeof(SF_INFO));
  memset(&sfInfoOut, 0, sizeof(SF_INFO));

  //Open the original sound files as read mode
  inFile1 = sf_open("sine.wav", SFM_READ, &sfInfoIn1);
  if(!inFile1){
    printf ("Error : could not open file : sine.wav\n");
    puts (sf_strerror (NULL));
    return 1;
  }
  
  //Open the original sound file as read mode
  inFile2 = sf_open("square.wav", SFM_READ, &sfInfoIn2);
  if(!inFile2){
    printf ("Error : could not open file : sine.wav\n");
    puts (sf_strerror (NULL));
    return 1;
  }

  //Check if the file format is in good shape
  if(!sf_format_check(&sfInfoIn1) || !sf_format_check(&sfInfoIn2)){	
    sf_close(inFile1);
    sf_close(inFile2);
    printf("Invalid encoding\n");
    return 1;
  }

  //Copy the output file format from first audio file
  sfInfoOut.samplerate = sfInfoIn1.samplerate;
  sfInfoOut.channels = sfInfoIn1.channels;
  sfInfoOut.format = sfInfoIn1.format;

  //Open another sound file in write mode
  outFile = sf_open("combined.wav", SFM_WRITE, &sfInfoOut);

  //Check if the file was succefully opened
  if(!outFile){	
    printf ("Error : could not open file : combined.wav");
    puts (sf_strerror(NULL));
    return 1;
  }

  //Allocate enough memory space to hold all samples from the input file
  buffer = (float *) malloc(sfInfoIn1.frames * sizeof(float));

  //Copy samples from the original file to the new file
  sf_count_t readcount = sf_read_float(inFile1, buffer, sfInfoIn1.frames);
  printf("Sample count 1: %lld\nSamples read 1: %lld\n", sfInfoIn1.frames, readcount);

  //Copy samples from the original file to the new file
  sf_write_float(outFile, buffer, readcount);

  //Allocate enough memory space to hold all samples from the input file
  buffer = (float *) realloc(buffer, sfInfoIn2.frames * sizeof(float));

  //Copy samples from the original file to the new file
  readcount = sf_read_float(inFile2, buffer, sfInfoIn2.frames);
  printf("Sample count 2: %lld\nSamples read 2: %lld\n", sfInfoIn2.frames, readcount);

  //Copy samples from the original file to the new file
  sf_write_float(outFile, buffer, readcount);

  //Close the open files
  sf_close(inFile1);
  sf_close(inFile2);
  sf_close(outFile);

  return 0;
}
