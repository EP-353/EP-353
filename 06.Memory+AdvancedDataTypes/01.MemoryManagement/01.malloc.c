/* A program that shows example usage of malloc() and free()

To compile and run this program, type:
clang 01.malloc.c -o 01.malloc && ./01.malloc
*/

#include <stdio.h>
#include <stdlib.h> //Include <stdlib.h> to use malloc() and free()

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

  // Free the memory after using
  free(array);
  
  return 0;
}
