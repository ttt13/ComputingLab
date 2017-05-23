#include <stdio.h>

int identical( int a[], int b[], unsigned int len )
{
	if (len == 0){
		return 1;
	}
	else {
		for (int i = 0; i < len; i++){
			if (a[i] != b[i]){
				return 0;
			}

		}
	return 1;
	}
}

