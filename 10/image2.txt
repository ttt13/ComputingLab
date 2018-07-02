#include <stdint.h> // for uint8_t
#include <cstdio>
#include "image2.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

/*class Image {
  
public:
  unsigned int cols;
  unsigned int rows;
  uint8_t* pixels;
  */
/* Constructs an image of 0x0 pixels. */
 Image::Image()
{
  cols = 0;
  rows = 0;
  pixels = NULL;  
}

Image::~Image()
{
  cols = 0;
  rows = 0;
  delete[] pixels;
}

/* Changes the size of an image, allocating memory as necessary, and
 setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
  cols = width;
  rows = height;
  int newLen = width * height;
  pixels = new uint8_t [newLen];

  if(pixels != NULL){
    for (int i = 0; i < newLen; i++){
      pixels[i] = fillcolor;
    }   
    return 0;
  }
  else{
    return 1;
  }
}

/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
 error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
  if(x < cols && y < rows && x >= 0 && y >= 0 && pixels != NULL){
    pixels[x + y*cols] = color;
    return 0;
  }
  else{
    return 1;
  }
}

/* Gets the color of the pixel at (x,y) and stores at the address pointed to 
 by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
  if(x < cols && y < rows && x >= 0 && y >= 0 && pixels != NULL){
    if( colorp != NULL ){
      *colorp = pixels[x + y*cols];
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    return 1;
  }

}
/* Saves the image in the file filename. In a format that can be
   loaded by load().  Returns 0 on success, else a non-zero error
   code. */
int Image::save( const char* filename )
{
  std::ofstream f;
  if (filename != NULL){
    int newLen = cols * rows;
    f.open(filename);
    char cString[20];
  	char rString[20];

  	//convert to strings
  	sprintf(cString, "%d", cols);
  	sprintf(rString, "%d", rows);
    f << cString << std::endl;
    f << rString << std::endl;

    for (int n = 0; n < newLen; n++){
    	char pStr[20];
  		sprintf(pStr, "%d", pixels[n]);
  		if (n == newLen - 1){
  			f << pStr;
  		}
  		else{
  			f << pStr << std::endl;
  		}
    }

    f.close();
    return 0;
  }
  else{
    return 1;
  }


/* Load an image from the file filename, replacing the current
   image size and data. The file is in a format that was saved by
   save().  Returns 0 success, else a non-zero error code . */
}
int Image::load( const char* filename )
{

	if (filename != NULL){
		ifstream inputF(filename);
	    //inputF.open(filename);
	    string readLine;
	    int checkPixels = 0; 
	    int readWidth = 0;
	    int readHeight = 0;
	    int counter = 0;
	    int p = 0;
	   	cols = 0;
	    rows = 0;
	    int curInput;
	   	bool getCols = false;
	   	bool getRows = false;
	   	if(inputF){
	   		if( inputF.is_open() ){
			    while ( getline(inputF, readLine) ){

			    	istringstream(readLine) >> curInput;

			    	if(getCols == false){
			    		cols = curInput;
			    		getCols = true;
			    		counter = 1;
			    	}
			    	else if(getCols == true && getRows == false ){
			    		rows = curInput;
			    		getRows = true;
			    	}
			    	else if (getCols == true && getRows == true && p < cols * rows){
			    		if( checkPixels == 0 ){
				    		if ( pixels != NULL ){
				    			delete[] pixels;
				    		}
				    		pixels = new uint8_t [cols * rows];
				    		checkPixels = 1;
				    	}
				    	pixels[p] = curInput;
				    	p++;
			    	}
			    }
			    inputF.close();
			    return 0;
			}
			//printf("Didn't work.\n");
			return 1;
		}
		else{
			//printf("Didn't work\n");
			return 1;
		}
	}
	else{
		//printf("Didn't work.\n");
		return 1;
	}
}


/*
int main( void )
{
	Image img;
	img.resize( 10, 10, 255) == 0;
	//for (int x = 0; x < 10; x++){
	//	printf("%d\n", img.pixels[x]);
	//}
	//printf("set_pixel test.\n");
	img.set_pixel(0, 0, 1);
	//for (int x = 0; x < 10; x++){
	//	printf("%d\n", img.pixels[x]);
	//}
	uint8_t gotPixel;
	uint8_t* colorp = &gotPixel;
	img.get_pixel(0,0, colorp);
	//printf("%d colorp\n", *colorp);
	img.save("test.txt");

	img.load("test.txt");
	for ( int y = 0; y < (img.cols)*(img.rows); y++){
		printf("%d pixels, %d \n", img.pixels[y], y);
	}
	printf("Cols = %d, Rows = %d\n", img.cols, img.rows);
	return 0;
}*/