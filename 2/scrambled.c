#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	int rangeA[100];
	int rangeB[100];
	int counter = 0;

	if (len == 0)
	{
	return 1;
	}
	else
	{
		for (int x = 0; x < 100; x++)
		{
			rangeA[x] = x;
			//printf("%d\n", rangeA[x]);
		}
		for(int i = 0; i < len; i++)
		{
			if (a[i] == 0)
			{
				rangeA[a[i]] += 1;
			}
			else
			{
			rangeA[a[i]] += a[i];
			}
		}
		for(int n = 0; n < 100; n++)
		{
			rangeB[n] = n;
		}

		for(int c = 0; c < len; c++)
		{
			if (b[c] == 0)
			{
				rangeB[b[c]] += 1;
			}
			else
			{
				rangeB[b[c]] += b[c];
			}
		}
		for(int y = 0; y < 100; y++)
		{
			if (rangeA[y] != rangeB[y])
			{
				counter += 1;
			}
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
}
