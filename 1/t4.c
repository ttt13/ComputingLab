#include <math.h>
#include <stdio.h>

int main( void )
{
        float i = 0;
        int ii = scanf("%f", &i);
	if ( ii != 1  ) {
		printf( "scanf error: (%d)\n", ii );
	} else {
		printf("%d %d %d\n", (int)floor(i), (int)round(i), (int)ceil(i) );
	}
        return 0;
}

