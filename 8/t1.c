#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "point_array.h"


/*//------->For reference<-------//
typedef struct point
{
  double x, y, z;
} point_t;

typedef struct 
{
  // number of points in the array
  size_t len;
  
  // pointer to an array of point_t structs
  // There is space for 'allocated' structs, but 
  // 'len' structs have been used so far.
  point_t* points;
  
  // for Task 2, do not use for Task 1
  size_t reserved; 

} point_array_t;
//////////////////////////////////*/

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
	//Make sure that pa isn't null, otherwise fail.
	assert(pa != NULL);
	pa->len = 0;
	assert(pa->len == 0);
	pa->points = malloc( sizeof(point_t) );
	assert(pa->points != NULL);
	assert(pa != NULL);
}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa )
{
	assert(pa != NULL);
	pa->points = NULL;
	free(pa->points);
}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p )
{
	assert(pa != NULL);
	if (pa == NULL){
		return 1;
	}
	pa->len++;
	pa->points = realloc( pa->points, sizeof(point_t) * pa->len );
	//Put the new point_t into the array.
	if( pa->points != NULL){
		pa->points[pa->len-1] = *p;
		return 0;
	}
	else{
		return 1;
	}
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
// Return 0 on success and 1 on failure.
int point_array_remove( point_array_t* pa, unsigned int i )
{
	assert(pa != NULL);
	if (pa == NULL){
		return 1;
	}
	if (pa->len == 0){
		printf("Nothing to remove.\n");
		return 1;
	}
	if (pa->len == 1){
		if(i != 0){
			printf("Index out of range.\n");
			return 1;
		}
		pa->len = 0;
		pa->points = NULL;
		return 0;
	}

	if (i >= 0 && i < pa->len){
		pa->points[i] = pa->points[pa->len-1];
		pa->len --;
		pa->points = realloc(pa->points, sizeof(point_t) * pa->len );
		return 0;
	}
	else{
		return 1;
	}
}

