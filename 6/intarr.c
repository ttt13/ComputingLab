#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "intarr.h"
#include <stdint.h>
#include <stdlib.h>

// Provides a bounds-checked, resizable array of integers with
// random-access and stack interfaces, and several utility functions
// that operate on them.

// **Lab 5 Task 1**

// Part 1
// Creates new intarr_t with size len. If successful, returns
// pointer. Else, returns NULL.

intarr_t* intarr_create( unsigned int len)
{
	intarr_t* newIntArr = NULL;
	newIntArr = malloc( sizeof(intarr_t) );
	if( newIntArr != NULL){
		newIntArr->data = malloc( len * sizeof(int) );
		if ( newIntArr->data != NULL){
			newIntArr->len = len;
		}
		else{
			free(newIntArr);
		}
	}
return newIntArr;

} 

// T1 Part 2
void intarr_destroy( intarr_t* ia )
{
	if (ia == NULL && ia->data != NULL){
		free(ia->data);
	}
	else if (ia != NULL){
		free(ia);
	}
}

// **Lab 5 Task 2**

// Part 1
// If index valid, set value at ia->data[index] to val,
// return INTARR_OK. Else, leave unchanged, return 
// INTARR_BADINDEX. If ia NULL, return INTARR_BADARRAY.

intarr_result_t intarr_set( intarr_t* ia, 
	unsigned int index, int val )
{
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if( index < ia->len && index >= 0 ){
		 ia->data[index] = val;
		 return INTARR_OK;
	}
	else if (index >= ia->len || index < 0){
		return INTARR_BADINDEX;
	}
}

// Part 2

intarr_result_t intarr_get( const intarr_t* ia,
	unsigned int index, int* i )
{
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if (index >= 0 && index < ia->len && i != NULL){
		*i = ia->data[index];
		return INTARR_OK;
	}
	else if (index < 0 || index >= ia->len || i == NULL){
		return INTARR_BADINDEX;
	}
}

// ***LAB 5 TASK 3***

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia )
{
	unsigned int numbytes;
	// Declare duplicate.
	intarr_t* duplicate;
	if ( ia != NULL ){
		duplicate = malloc(sizeof(intarr_t));
		duplicate->len = ia->len;
		numbytes = (duplicate->len * sizeof(int));
		//duplicate->data = malloc(numbytes);
		if( ia->data != NULL ){
			duplicate->data = malloc(numbytes);
			memcpy(duplicate->data, ia->data, numbytes);
		}
		else{
			free(duplicate);
		}
	}
	else{
		free(duplicate);
	}
return duplicate;
}


/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia )
{
	int smallest;
	int temp;
	//Selection sort.
	if (ia != NULL){
		for (int i = 0; i < (ia->len)-1; i++){
			smallest = i;
			for (int j = (i+1); j < ia->len; j++){
				if(ia->data[j] < ia->data[smallest]){
					smallest = j;
				}
			}
		temp = ia->data[i];
		ia->data[i] = ia->data[smallest];
		ia->data[smallest] = temp;
		}
	return INTARR_OK;
	}


	else{
		return INTARR_BADARRAY;
	}
}

/* LAB 5 TASK 5 */

// Find the first occurence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
	if ( ia != NULL ){
		for ( int x = 0; x < ia->len; x++ ){
			if( ia->data[x] == target ){
				if ( i != NULL ){
					*i = x;
					return INTARR_OK;
				}
			}
		}
		return INTARR_NOTFOUND;
	}
	else{
		return INTARR_BADARRAY;
	}
}
/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
// Take a look at TASK 7 below and see if it might be helpful
intarr_result_t intarr_push( intarr_t* ia, int val )
{
	if (ia != NULL){
		//intarr_t* x = malloc(sizeof(intarr_t));
		//int numbytes = malloc(ia->len * sizeof(int));
		//x->data = numbytes;
		//memcpy(x->data, ia->data, numbytes);
		ia->data = realloc( ia->data, ((ia->len) + 1) * sizeof(int));
		if (ia->data != NULL){
			ia->data[ia->len] = val;
			ia->len += 1;
			return INTARR_OK;
		}
		else{
			return INTARR_BADALLOC;
		}
	}
	else{
		return INTARR_BADARRAY;
	}
}
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
// Take a look at TASK 7 below and see if it might be helpful
intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
	if (ia != NULL){
		if (ia->len == 0){
			return INTARR_BADINDEX;
		}
		if (i != NULL){
			if (ia->data != NULL){
				*i = ia->data[ (ia->len) -1 ];
				ia->data = realloc( ia->data, ((ia->len) - 1) * sizeof(int) );
				ia->len -= 1;
				return INTARR_OK;
			}
		}
		else{
			return INTARR_BADINDEX;
		}
	}
	else{
		return INTARR_BADARRAY;
	}
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
	if (ia != NULL){
		if (newlen == ia->len){
			if (ia->data == NULL){
				return INTARR_BADALLOC;
			}
			else{
				return INTARR_OK;
			}
		}
		if (newlen > ia->len){
			//ia->data = realloc(ia->data, newlen*sizeof(int));
			if (ia->data != NULL){
				ia->data = realloc(ia->data, newlen*sizeof(int));
				for (int i = ia->len; i < newlen; i++){
					ia->data[i] = 0;
				}
				ia->len = newlen;
				return INTARR_OK;
			}
			else if (ia->data == NULL){
				return INTARR_BADALLOC;
			}
		}
		else if (newlen < ia->len){
			//ia->data = realloc(ia->data, newlen*sizeof(int));
			ia->len = newlen;
			if (ia->data != NULL){
				ia->data = realloc(ia->data, newlen*sizeof(int));
				return INTARR_OK;
			}
			else if (ia->data == NULL){
				return INTARR_BADALLOC;
			}

		}
	}
	else{ // If ia == NULL
		return INTARR_BADARRAY;
	}
}
/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
	intarr_t* duplicate;
	if (last < first || ia == NULL || first < 0 || last >= ia->len){
		free(duplicate);
	}
	else{
		duplicate = malloc(sizeof(intarr_t));
		int newlen = last - first + 1;
		duplicate->len = newlen;

		int counter = 0; // to count indices of duplicate.
		unsigned int numbytes = (newlen * sizeof(int));
		if(ia->data != NULL){
			duplicate->data = malloc( numbytes );

			for ( int i = first; i <= last; i++ ){
				duplicate->data[counter] = ia->data[i];
				counter ++;
			}
		}
		else{
			free(duplicate);
		}
	}

	return duplicate;
}
/* LAB 5 ENDS HERE */

/* -------------------------------------------------------------- */
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
		free(ia);
		return ia;
	}
	int hdr[1];

	if ( fread(hdr, sizeof(int), 1, f) != 1){
		printf("Failed to read header.\n");
		free(ia);
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
return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{
	intarr_t* ia;
return ia;
}
