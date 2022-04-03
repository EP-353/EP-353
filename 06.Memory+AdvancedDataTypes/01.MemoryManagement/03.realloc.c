/* A program that shows example usage of malloc(), realloc(), and free()

To compile and run this program, type:
clang 03.realloc.c -o 03.realloc && ./03.realloc
*/

#include <stdio.h>
#include <stdlib.h> //Include <stdlib.h> to use malloc(), realloc() and free()

int main() {
  // malloc() equivalent of "int array[10]"";
  int *array = malloc(10 * sizeof(int));
  
  // Check for null pointer
  if (array == NULL) {
    fprintf(stderr, "malloc failed\n");
    return -1;
  }
  
  //Do something with the array
  for (int i = 0; i < 10; i++){
    array[i] = i + 1;
  }
  
  printf("Number sequence: ");
  for (int i = 0; i < 10; i++){
    printf("[%d]", array[i]);
  }
  printf("\n");

  //resize the array using realloc()
  array = realloc(array, 11*sizeof(int));
  
  //Check the content after realloc
  printf("Number sequence after realloc(): ");
  for (int i = 0; i < 11; i++){
    printf("[%d]", array[i]);
  }
  printf("\n");

  // Free the memory after using
  free(array);
  
  return 0;
}
