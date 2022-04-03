#include <stdio.h>
#include <math.h>

//Excute this code using:
//clang 02.SineWave.c -o 02.SineWave; ./02.SineWave

int main () {
  double radians, ratio;

  // Open CSV file (Comma Separated Values)
  // We can then open the file in Excel and plot.
  FILE *file;
  file = fopen("SineWave.csv", "w");
  if(!file){
    printf("Cannot open SineWave.csv.\n");
    return 1;
  }

  // Go through the unit circle (0° ~ 360°)
  for (int degrees = 0; degrees <= 360; degrees++){
    
    // Convert degrees to radians
    radians = degrees * (M_PI / 180);

    // Get the ratio of opposite and hypotenuse (-1 ~ 1)
    ratio = sin(radians);

    // Write the result to the csv file 
    fprintf(file, "%d, %f\n", degrees, ratio);
    printf("%d: %.3f\n", degrees, ratio);
  }

  if(file) fclose(file);

  return 0;
}