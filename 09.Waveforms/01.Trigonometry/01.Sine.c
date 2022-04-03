#include <stdio.h>
#include <math.h>

//Excute this code using:
//clang 01.Sine.c -o 01.Sine; ./01.Sine

int main () {
   double degrees, radians, ratio;
   // Define an angle in degrees (0° ~ 360°)
   degrees = 45.0;

   // Convert degrees to radians (0 ~ 2π). 
   // M_PI is a constant value from math.h
   // that has the value of π.
   radians = degrees * (M_PI / 180);

   //Get the ratio of opposite and hypotenuse (-1 ~ 1)
   ratio = sin(radians);

   printf("The sine of %.2lf degrees is %lf", degrees, ratio);

   return 0;
}