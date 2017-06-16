#include <stdint.h>
#include "imgops.h"
#include <math.h>

int pythagorean(double ax, double by)
{
	int hyp = round( sqrt( pow(ax,2) + pow(by,2) ) );
	return hyp;
}
void draw_circle( uint8_t img[], unsigned int cols, unsigned int rows,
	int x, int y, int r, uint8_t color)
{
if(r > 0){
	//Find the centre of the circle, paint it the color.
	for (int c = 0; c < rows; c++){
		for (int d = 0; d < cols; d++){
			if ( d == x && c == y ){
				set_pixel(img, cols, rows, d, c, color);
			}
		}
	}
	// Colour horizontal and vertical circumfirance.
double hypo = 0;
double xhypo = 0;
double yhypo = 0;
	for (int e = 0; e < rows; e++){
		for (int f = 0; f < cols; f++){
			if ( e == y ){
				if( (f >= (x-r)) && (f <=(x+r)) ){
					set_pixel(img, cols, rows, f, e, color);
				}
			}
			if ( f == x ){
				if( (e >= (y-r)) && (e <= (y+r)) ){
					set_pixel(img, cols, rows, f, e, color);
				}
			}
			else if (f != x && e != y){
				if ( f < x ){
					xhypo = ( (double)f + 0.5);
				}
				else{
					xhypo = ((double)f - 0.5);
				}
				if (e < y){
					yhypo = ( (double)e + 0.5);
				}
				else{
					yhypo = ( (double)e - 0.5);
				}
				hypo = sqrt( pow(xhypo - x,2) + pow(yhypo - y,2) );
				if (hypo < r){
					set_pixel(img, cols, rows, f, e, color);
				}
			}
	// Colour diagonal using Pythagorean Formula
			/*else if( f != x && e != y ){
				if (e < y && f > x){ // Quad I f <x
					testx = f - ((float)x) - 0.5;
					//printf("%f\n", testx);
					testy = ((float)y) - e - 0.5; // -0.5
					hypo = (sqrt( pow(testx, 2) + pow(testy, 2) ));
					if (hypo < r){
						set_pixel(img, cols, rows, f, e, color);
					}
				}
				if (e < y && f < x){ // Quad II CORRECT!
					testx =  ((float)x)-f - 0.5;
					testy = ((float)y)-e - 0.5;
					hypo = (sqrt( pow(testx, 2) + pow(testy, 2) ));
					if (hypo < r){
						set_pixel(img, cols, rows, f, e, color);
					}
				}
				if (e > y && f < x){ // Quad III
					testx = ((float)x)-f - 0.5;
					testy = e- ((float)y) - 0.5;
					hypo = (sqrt( pow(testx, 2) + pow(testy, 2) ));
					if (hypo < r){
						set_pixel(img, cols, rows, f, e, color);
					}
				}
				if (e > y && f > x){ // Quad IV
					testx = f-(float)x - 0.5;
					testy = e-(float)y - 0.5;
					hypo = (sqrt( pow(testx, 2) + pow(testy, 2) ));
					if ( hypo < r){
						set_pixel(img, cols, rows, f, e, color);
					}
				}
			}*/
		}
	}
} // <<< This one is for the if statement at the very top.
} // <<< For the function.

