#include <stdio.h>
#include <math.h>

int main( void )
{
	float x = 0; // Width (base value)
	float y = 0; // Depth (height value)
	float z = 0; // Length **Irrelevant**
	float a = 0; // Counter to evaluate left and right
	float b = 0; // Counter to print hashtags
	char hashtag = '#';
	char dot = '.';
	char nothing = ' ';
	float left = 0; // For left '#' placement location
	float right = 0; // For right '#' placement location

	scanf("%f %f %f", &x, &z, &y);

	for ( a = (y - 1); a >= 0; a-- ){
		left = floor( a * ( x / (2 * y) ) );
		right = ceil( (x-1) + (-a) * ( x/(2 * y) ) );

		for ( b = (x - 1); b >= 0; b-- ){
			if( a == (y-1) || a == 0 ){
				if ( b < left || b > right ){
					printf("%c", nothing);
				}
				else{
				printf("%c", hashtag);
				}
			}
			else if( a < y || a > 0 ){
				if( b < left || b > right ){
					printf("%c", nothing);
				}
				else if( b == left || b == right){
					printf("%c", hashtag);
				}
				else{
					printf("%c", dot);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
