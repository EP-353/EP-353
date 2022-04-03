/* A program that shows example usage of calloc() and free()

To compile and run this program, type:
clang 02.calloc.c -o 02.calloc && ./02.calloc
*/

#include <stdio.h>
#include <stdlib.h> //Include <stdlib.h> to use calloc() and free()

int main() {
  // calloc() equivalent of "int array[10]"";
  // elements of array are initialized to 0.
  int *array = calloc(10, sizeof(int));
  
  // Check for null pointer
  if (array == NULL) {
    fprintf(stderr, "calloc failed\n");
    return -1;
  }

  // Check if array elements are all zeros  
  printf("Number sequence: ");
  for (int i = 0; i < 10; i++){
    printf("[%d]", array[i]);
  }
  printf("\n");

  // Free the memory after using
  free(array);
  
  return 0;
}
