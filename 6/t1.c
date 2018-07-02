#include <stdio.h>
#include "intarr.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename )
{
	//Does filename exist? Come up with guard for it?
	FILE *f = fopen(filename, "w");

	if ( f == NULL ){
		printf("Couldn't open file.\n");
		return 1;
	}
	if (ia != NULL){
		int hdr[1];
		hdr[0] = ia->len;

		if ( fwrite(hdr, sizeof(int), 1, f) != 1){
			printf("Failed to write header.\n");
			return 2;
		}

		//Pretty sure we know the length (:
		if ( fwrite(ia->data, sizeof(int), ia->len, f) != ia->len ){
			printf("Couldn't write file.\n");
			return 1;
		}

		fclose( f );

return 0;
	}
	else{
		return 1;
	}
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename )
{
	intarr_t* ia;
	ia = malloc( sizeof(intarr_t) );

	//Do we need a guard for if filename doesn't exist?
	FILE *f = fopen(filename, "r");

	if ( f == NULL ){
		printf("Couldn't open file.\n");
		ia = NULL; // free(ia); was originally here.
		return ia;
	}
	int hdr[1];

	if ( fread(hdr, sizeof(int), 1, f) != 1){
		printf("Failed to read header.\n");
		ia = NULL; //free(ia); was originally here.
		return ia;
	}
	ia->len = hdr[0];

	ia->data = malloc( ia->len * sizeof(int) );

	if ( fread(ia->data, sizeof(int), ia->len, f) != ia-> len ){
		printf("Couldn't read data.\n");
		free(ia);
		return(ia);
	}

	// For testing.
	/*for(int i = 0; i < len; i++){
		printf("%d\n", ia->data[i]);
	}*/

	fclose(f);

return ia;
}
