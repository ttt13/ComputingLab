#include <stdio.h>

int main( void )
{
	int i = 0; // Counter for the # length
	int n = 0; // Counter for the # top row
	char hashtag = '#';
	char period = '.';
	int result = 0;
	int j = 0; // Counter for the # bottom row
	int k = 0; 
	int x = 0; // length
	int y = 0; // width
	int z = 0; // height (irrelevant)

	scanf("%d %d %d", &x, &y, &z);

	for ( n = 0; n < x; n++ ){ // this will print the length.
		printf("%c", hashtag);
	}
	printf("\n");

	if ( y != 1 && x != 1 ){

		for ( i = 0; i < (y-2); i++ ){ // Width -2 because top and bottom contained in length.
			printf("%c", hashtag);

			for ( k = 0; k < (x-2); k++ ){ // periods in the width
				printf("%c", period);
			}
			printf("%c", hashtag);

			printf("\n");
		}

		for (j = 0; j < x; j++){ // bottom
			printf("%c", hashtag);
		}
	printf("\n");
	}
	return 0;
}



