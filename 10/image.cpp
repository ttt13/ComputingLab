#include "image.hpp"
#include <stdint.h>
#include <cstdio>

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
		if(colorp != NULL){
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

/*
int main( void )
{
	Image img;
	img.resize( 10, 10, 255) == 0;
	for (int x = 0; x < 10; x++){
		printf("%d\n", img.pixels[x]);
	}
	printf("set_pixel test.\n");
	img.set_pixel(0, 0, 1);
	for (int x = 0; x < 10; x++){
		printf("%d\n", img.pixels[x]);
	}
	uint8_t gotPixel;
	uint8_t* colorp = &gotPixel;
	img.get_pixel(0,0, colorp);
	printf("%d colorp\n", *colorp);
	return 0;
}*/