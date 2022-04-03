/* C program for variable creation, initialization, and access.

To compile and run this program type:
clang 01.Variables.c -o 01.Variables && ./01.Variables
*/

#include <stdio.h>

int main(){
	//Declare and initialize variables
	int number = 123;
	double pi = 3.1416;
	float z = 40.5f;
	char c = 'A';
	char *str = "Hello World";

	//Print their values	
	printf("number: %d, pi: %f, z: %f, c: %c, str: %s\n", number,  pi, z, c, str);
	
	//Change values in each variable
	number = 234;
	pi = 3.14159265;
	z = .12f;
	c = 'a';
	str = "Hello Variables";
	
	//Print their values	
	printf("number: %d, pi: %f, z: %f, c: %c, str: %s\n", number,  pi, z, c, str);

	printf("%c", '\n');
		
	return 0;
}