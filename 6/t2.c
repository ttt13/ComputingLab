#include <stdio.h>
#include "intarr.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename )
{
  //Does filename exist? Come up with guard for it?
  FILE *f = fopen(filename, "w");

  if ( f == NULL ){
    //printf("Couldn't open file.\n"); // Error message.
    return 1;
  }
  if (ia != NULL){
    /*int hdr[1];
    hdr[0] = ia->len;

      if ( fwrite(hdr, sizeof(int), 1, f) != 1){
        printf("Failed to write header.\n");
        return 2;
      }*/

      fprintf(f, "["); // Array brackets for JSON file

      for (int i = 0; i < ia->len; i++){

        if ( i == 0){ 
          fprintf(f, " %d", ia->data[i]); 
        }
        else{
          fprintf(f, ", %d", ia->data[i]);
        }
      }

      fprintf(f, " ]\n");

      fclose( f );

      return 0;
  }

  else{
    return 1;
  }

}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{
	FILE *f = fopen(filename, "r");

	if ( f == NULL ){ //If the file cannot be opened
		return NULL;
	}

	intarr_t* ia = intarr_create( 0 ); //Make int array with length 0

	char firstChar;
	fscanf(f, "%c ", &firstChar);

	int element;

	if (fscanf(f, " %d", &element)){
		intarr_push(ia, element);
	}

	while ( fscanf(f, ", %d", &element) ){
		intarr_push(ia, element);
	}

	fclose(f);

return ia;
}
