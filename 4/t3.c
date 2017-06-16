#include <stdint.h>
#include <stdio.h>
#include "imgops.h"
#include <math.h>

void life( uint8_t array[], unsigned int cols, unsigned int rows )
{
int checkX = 0;
int checkY = 0;
int living = 0;
int countArray[cols*rows];
int f = 0;
	for (int c = 0; c < cols*rows; c++){
		countArray[c] = 0;
	}

	for (int b = 0; b < rows; b++){
		for (int a = 0; a < cols; a++){
			for (int y = -1; y <= 1; y++){
				for (int x = -1; x <= 1; x++){
					if ( !(y == 0 && x == 0) ) {
						checkX = (a + cols + x) % cols;
						checkY = (b + rows + y) % rows;
						if ( array[checkY*cols + checkX] == 255 ){
							countArray[b*cols+a] ++;
						} 
					}
				}
			}


		}
	}
	for ( int d = 0; d < rows; d++){
		for ( int e = 0; e < cols; e++){
			f = d*cols+e;
			if (countArray[f] < 2){
				array[f] = 0;
			}
			if (array[f] == 255 && (countArray[f] == 2 || countArray[f] == 3) ){
				array[f] = 255;
			}
			if (countArray[f] > 3){
				array[f] = 0;
			}
			if (array[f] == 0 && (countArray[f] == 3) ){
				array[f] = 255;
			}
		}
	}
return;
}
