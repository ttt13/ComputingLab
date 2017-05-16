#include <math.h>
#include <stdio.h>

int main( void )
{
	float i = 0;
	float result = 0;
	while( result != EOF )
		{
        	result = scanf("%f", &i);
		if ( result != EOF )
		{
			printf("%d %d %d\n", (int)floor(i), (int)round(i), (int)ceil(i) );
		}
       		}
	printf("Done.\n");
        return 0;
}

