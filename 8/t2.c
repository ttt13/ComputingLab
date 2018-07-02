#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "point_array.h"
#include <stdint.h>


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
	pa->reserved = 1;
	pa->points = malloc( (pa->reserved) * sizeof(point_t) );
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
	/*assert(pa != NULL);
	assert(p != NULL);
	if (pa == NULL || p == NULL){
		return 1;
	}
	
	if (pa->len >= pa->reserved){
		size_t newLen = pa->len * 2 + 1;
		size_t newSize = newLen * sizeof(point_t);

		point_t* temp = realloc( pa->points, newSize );
		pa->points = temp;	
		pa->reserved = newLen;
	}
	//Put the new point_t into the array.
		pa->points[pa->len-1] = *p;
		pa->len++;
		return 0;*/

	assert( pa );
    assert( p );

    if( pa->len >= pa->reserved )
    {
        size_t newLen = pa->len * 2 + 1;  // add 1 to take care of a NULL array
        size_t newSize= newLen * sizeof(point_t);
        point_t* temp = realloc( pa->points, newSize );

        pa->points = temp;
        pa->reserved = newLen;
    }
    pa->points[pa->len] = *p; // copy struct into array
    pa->len++;
    return 0;
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

