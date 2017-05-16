#include <math.h>
#include <stdio.h>

int main( void )
{
	float i = 0;
	scanf("%f", &i);
	printf("%d %d %d\n", (int)floor(i), (int)ceil(i), (int)round(i));
	return 0;
}
