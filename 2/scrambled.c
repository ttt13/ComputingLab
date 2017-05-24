#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	unsigned int temp = 0;
	int counter = 0;
	if (len == 0){
		return 1;
	}else{
		for (int i = 0; i < len; i++){
			temp = a[i];
			for (int n = 0; n < len; n++){
				if (b[n] == temp){
					counter += 1;
				}
			}
		}
		if (counter == len){
			return 1;
		}else{
			return 0;
		}
	}
}

int main( void )
{
	unsigned int a[] = {};
	unsigned int b[] = {};

	if( scrambled(a,b,8) == 1 ){
		printf("b same as a");
	}else{
		printf("b different");
	}

	return 0;
}

