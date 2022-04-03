/* A C program that shows examples of switch statement. 

To compile and run this program, type:
clang 03.Switch.c -o 03.Switch && ./03.Switch
*/

#include <stdio.h>

int main() {  
  char noteName = 'A';

  printf("Find the names of a scale degrees in the C Major Scale,\n");
  switch (noteName) {
    case 'C':
    case 'c':
      printf("\nC is the \"tonic\" in the key of C.\n");
      break;

    case 'D':
    case 'd':
      printf("\nD is the \"supertonic\" in the key of C.\n");
      break;

    case 'E':
    case 'e':
      printf("\nE is the \"mediant\" in the key of C.\n");
      break;

    case 'F':
    case 'f':
      printf("\nF is the \"subdominant\" in the key of C.\n");
      break;

    case 'G':
    case 'g':
      printf("\nG is the \"dominant\" in the key of C.\n");
      break;

    case 'A':
    case 'a':
      printf("\nA is the \"submediant\" in the key of C.\n");
      break;

    case 'B':
    case 'b':
      printf("\nB is the \"leading tone or subtonic\" in the key of C.\n");
      break;

    default:
      printf("This note is not in the C major scale!\n");
  }

  return 0;
}