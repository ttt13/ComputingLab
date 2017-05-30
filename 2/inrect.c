#include <stdio.h>

int InRectangle(float pt[2], float rect[4])
{
	if ((rect[0] > rect[2]) && (rect[1] > rect[3]) ){
		if ( (pt[0] <= rect[0] && pt[0] >= rect[2]) && (pt[1] <= rect[1] && pt[1] >= rect[3]) ){
			printf("True\n");
			return 1;
		}
		else{
			printf("False\n");
			return 0;
		}
	}


	else if ( (rect[0] < rect[2]) && (rect[1] < rect[3]) ){	
		
		if ( (pt[0] >= rect[0]) && (pt[0] <= rect[2]) && (pt[1] >= rect[1]) && (pt[1] <= rect[3]) ){
			printf("True\n");
			return 1;
		}
		else{
			printf("False\n");
			return 0;
		}
	}
}