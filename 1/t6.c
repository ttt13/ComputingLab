#include <math.h>
#include <stdio.h>

int main ( void )
{
	float max = 0;
	float min = 0;
	float sum = 0;
	float current = 0;
	int result = 0;
	int counter = 0;
	if (result != EOF)
	{
		result = scanf("%f", &current);
		sum = current;
		counter = 1;
		max = current;
		min = current;
	}
	while(result != EOF)
	{
		result = scanf("%f", &current);
		if (result != EOF)
		{
			counter += 1;
			sum += current;
			if ( max < current )
			{
				max = current;
			}
			if ( min > current )
			{
				min = current;
			}
		}
	}
	printf("%0.2f %0.2f %0.2f\n", min, max, sum/counter);
	return 0;
}

