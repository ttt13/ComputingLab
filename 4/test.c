/*
 * test.cc - functions, arrays, pointers, image representation
 * Richard Vaughan 2014
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"

// TASK 1 LAB 4

#include "t1.h"

int main( int argc, char* argv[] )
{
  const unsigned int winwidth  = 160;
  const unsigned int winheight = 160; 

  unsigned int imgwidth  = 16;//winwidth / 4;//16
  unsigned int imgheight = 16;//winheight / 4 ; //16
    
  // initialize the graphics system
  draw_startup( (char*)"Grey Array", winwidth, winheight );
  
  uint8_t* img = NULL; 
  
  if( argc == 2 ) // if a filename was specified
    {
      uint32_t depth=0;
      int alpha=0;
      if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
	{
	  printf( "failed to load image %s\n", argv[1] );
	  exit(1);
	}      
    }
  else // no filename specified: create a blank image
    {
      // allocate an array for our image
      img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
      if( img == NULL )
	{
	  printf( "failed to allocate memory for image.\n" );
	  exit(1);
	}      
      
      // set the whole array to zero (black)
      memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));      
    }
  
  // todo: this is a good place to use some image-modifying functions from imgops.c
  
  // >>>>>********for LAB 4**********<<<<<
	draw_circle( img, 16, 16, 8, 8, 1, 255);



  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img, imgwidth, imgheight );
  
  // finalize the graphics system, freeing its resources
  draw_shutdown();

  // every malloc() should have a matching free()
  free(img);

  return 0;
}

