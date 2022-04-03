#include<stdio.h>

//Compile with:
//clang 01.CallbackFunction.c -o 01.CallbackFunction -lsndfile
//Run with:
//./01.CallbackFunction

//callback and caller function prototypes
void callback();
void caller(void (*ptr)());

int main() {
   void (*ptr)() = &callback;
   caller(ptr);
   return 0;
}

void callback() {
   printf("I am a callback function!\n");
}

void caller(void (*ptr)()) {
   printf("I am calling the callback function\n");
   (*ptr)();   //call the callback function
}
