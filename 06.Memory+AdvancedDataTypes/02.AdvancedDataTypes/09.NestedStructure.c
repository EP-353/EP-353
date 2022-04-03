/* A program that shows example usage of nested structures.

To compile and run this program, type:
clang 09.NestedStructure.c -o 09.NestedStructure && ./09.NestedStructure
*/

#include <stdio.h>

struct Note {
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
}; //Semi-column at the end

//Let's typedef to avoid typing 'struct' again.
typedef struct Note Note;

// Create another struct that nests Note data type
// Also, typedef the statement together
typedef struct Trichord {
  Note notes[3];
} Trichord;

int main() {
	// Initialize chord 
	Trichord chord = {{
		{69, 127, 1},
		{71, 111, 1},
		{73, 95, 1}
	}};

	// If structure is nested, multiple ’.’ are required
	// In this case, we need to also consider that the member of 
	// Trichord is an array.
	printf("Pitch value of first note: %d.\n", chord.notes[0].pitch);

  return 0;
}
