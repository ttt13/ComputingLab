#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	int counter = 0;

	if(len == 0)
	{
		return 1;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			counter += (a[i] - b[i]);
		}
		if(counter == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
