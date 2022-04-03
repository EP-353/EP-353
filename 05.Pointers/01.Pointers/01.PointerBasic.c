/* A C program that shows how to use pointer.

To compile and run this program, type:
clang 01.PointerBasic.c -o 01.PointerBasic && ./01.PointerBasic
*/

#include <stdio.h>

int main() {
	// Variables
	int num = 4;
	float pi = 3.14159f;
	
	// Addresses of Variables
  // Syntax for a pointer variable:
  // type *name;
	int *pn = &num;
	float *ppi = &pi;
	
	// Print ppi
	printf("pi = %f\n", *ppi);
	
  // Print the address of ppi
	printf("pi = %p\n", ppi);
	
  // Operate on dereferenced pointer
	*ppi = *ppi + *pn;
  printf("pi + 4 = %f\n", *ppi);

  // null pointer
  int *p;

  return 0;
}