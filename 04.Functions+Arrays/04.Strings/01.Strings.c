/* A C program that shows the basic use of string in C.

To compile and run this program, type:
clang 01.String.c -o 01.String && ./01.String
*/

#include <stdio.h>

int main() {

  // Strings are represented with double quote enclosure
  // Compiler automatically adds \0 (null character) at the end of string
  char string[] = "String in C";

  // Print string using %s
  printf("%s\n", string);

  // Strings are array of characters. 
  // We can create it using the syntax for array 
  // but make sure to explicitly add \0 at the end
  char str[] = {
    'T', 'h', 'i', 's', ' ', 
    'i','s', ' ', 
    'a', ' ', 
    'S', 't','r','i','n','g',' ',
    't','o','o','\0'
  };

  // Let's verify that str is a string
  printf("%s\n", str);

  // What happens when string is not null terminalted?
  // Compiler does not know where the string ends...
  // We will get bogus characters at the end of "Hello"
  char word[] = {'H','e','l','l','o'};
  printf("%s\n", word); 

  
  return 0;
}