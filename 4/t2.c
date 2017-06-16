#include <math.h>
#include <stdint.h>
#include "imgops.h"

void draw_rectangle( uint8_t array[], unsigned int cols,
	unsigned int rows, int x, int y, int rect_width, int rect_height,
	uint8_t color)
{
	int xCoord = 0;
	int yCoord = 0;
	// Do this only if the height and the width aren't 0.
	// Find the corresponding x and y coordinates in order to draw the rectangle.
	// There are four cases, x is negative or positive, or y is negative or positive.
	//printf("x = %d, y = %d\n", x, y);
	if ( rect_height != 0 && rect_width != 0){
			if (rect_width < 0){
				xCoord = (x + rect_width +1) ;
			}
			else{
				xCoord = (x + rect_width -1) ;
			}
			if (rect_height < 0){
				yCoord = (y + rect_height +1);
			}
			else{
				yCoord = (y + rect_height -1);
			}
			//printf("xCoord = %d, yCoord = %d\n", xCoord, yCoord);
		for ( int findY = 0; findY < rows; findY ++){
			for (int findX = 0; findX < cols; findX ++){
				if ( (findX >= x && findX <= xCoord) || (findX <= x && findX >= xCoord) ){
					if( findY == y || findY == yCoord){
						set_pixel(array, cols, rows, findX, findY, color);
					}
					if( findY > y && findY < yCoord || findY < y && findY > yCoord){
						if ( findX == x || findX == xCoord){
							set_pixel(array, cols, rows, findX, findY, color);
						}
					}
				}
			}
		}
	}
}
	// Now go through the array. When reaching y coordinates, color all x's (top and bot perimeters of rectangle)
	// Otherwise, only color the side coordinates.
	/*for (int findY = 0; findY < rows; findY ++ ){
		for (int findX = 0; findX < cols; findX ++){
			if ( (findY >= y && findY <= yCoord) || (findY <= y && findY >= yCoord) ){
					if ( findY == yCoord || findY == y ){
						if ( (findX >= x && findX <= xCoord) || (findX <= x && findX >= xCoord) ){
							set_pixel(array, cols, rows, findX, findY, color);
						}
					}
					else{
						if ( (findY > y && findY < yCoord) || (findY < y && findY > yCoord)){
							if (findX == x || findX == xCoord){
								set_pixel(array, cols, rows, findX, findY, color);
							}
						}
					}
			}
		}
	}*/

// *** LONGER LESS EFFICIENT CODE *** //

	// Four cases: 1) Y Negative: a) X negative b) X positive. 2) Y Positive: a) X negative. b) X positive
		//If width and height are negative
		/*if(rect_width < 0 && rect_height < 0){
			for (int c = (y + rect_height + 1); c <= y; c++){
				for (int d = (x + rect_width + 1); d <= x; d++){
					if(c == y + rect_height + 1|| c == y){
						set_pixel(array, cols, rows, d, c, color);
					}
					else if (d == (x+rect_width + 1) || d == x){
						set_pixel(array, cols, rows, d, c, color);
					}
				}
			}
		}
		//Height negative, width positive.
		if(rect_width > 0 && rect_height < 0){
			for (int e = (y + rect_height + 1); e <= y; e++){
				for (int f = (x + rect_width - 1); f <= x; f++){
					if(e == y + rect_height + 1 || e == y){
						set_pixel(array, cols, rows, f, e, color);
					}
					else if (f == (x + rect_width - 1) || f == x){
						set_pixel(array, cols, rows, f, e, color);
					}
				}
			}
		}
		//Height positive, width positive.
		if(rect_width > 0 && rect_height > 0){
			for (int g = (y + rect_height - 1); g <= y; g++){
				for (int h = (x + rect_width -1); h <= x; h++){
					if(g == (y + rect_height - 1) || g == y){
						set_pixel(array, cols, rows, h, g, color);
					}
					else if (h == (x + rect_height - 1) || h == x){
						set_pixel(array, cols, rows, h, g, color);
					}
				}
			}
		}
		//Height positive, width negative.
		if(rect_width < 0 && rect_height > 0){
			for ( int i = (y + rect_height - 1); i <= y; i++ ){
				for ( int j = (x + rect_width + 1); j <= x; j++){
					if( i == (y + rect_height) || i == y ){
						set_pixel(array, cols, rows, j, i, color);
					}
					else if ( j == (x + rect_width) || j == x ){
						set_pixel(array, cols, rows, j, i, color);
					}
				}
			}
		} */
	
