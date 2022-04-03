/* A C program that shows how to use arrays with functions.

To compile and run this program, type:
clang 02.Array2Function.c -o 02.Array2Function && ./02.Array2Function
*/

#include <stdio.h>

//Function prototypes
void printArrayWithPointer(int *arr);
void printArrayWithSizedArray(int arr[10]);
void printArrayWithUnsizedArray(int arr[]);

int main() {
  int data[10]; //Declare an array

  // Initialize the content with for-loop
  for (int i = 0; i < 10; i++) {
    data[i] = i * i;
  }
  
  //Print the contents of array using functions
  printArrayWithPointer(data);
  printf("-------------------------------\n");
  printArrayWithSizedArray(data);
  printf("-------------------------------\n");
  printArrayWithUnsizedArray(data);

  return 0;
}

void printArrayWithPointer(int *arr){
  for (int i = 0; i < 10; i++){
    printf("Index %d contains: %d\n", i, arr[i]);
  }  
}

void printArrayWithSizedArray(int arr[10]){
  for (int i = 0; i < 10; i++){
    printf("Index %d contains: %d\n", i, arr[i]);
  }  
}

void printArrayWithUnsizedArray(int arr[]){
  for (int i = 0; i < 10; i++){
    printf("Index %d contains: %d\n", i, arr[i]);
  }  
}
