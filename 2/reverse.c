#include <stdio.h>

void reverse( int arr[], unsigned int len )
{
	int b[len];
	for (int i = 0; i < len; i++){
		b[i] = arr[len-1-i];
	}
	for (int i = 0; i < len; i++){
		arr[i] = b[i];
	}
}
