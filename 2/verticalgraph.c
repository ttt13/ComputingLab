#include <stdio.h>

int main(void)
{
	int result = 0;
	int i = 0;
	int array[80];
	int a = 0;
	int counter = 0;

	while(result = scanf("%d", &i) != EOF){
		array[a] = i;
		a++;
		counter ++;
	}
	for (a; a < 81; a++){
		array[a] = -1;
	}

	/* Finding the maximum now */
	int max = array[0];
	for (int c = 1; c < counter; c++){
		if (array[c] > max){
			max = array[c];
		}
	}

//Printing part
	while ((max -1) >= 0){
		for (int y = 0; y < counter; y++){
			if (array[y] < max){
				printf(" ");
			}
			if (array[y] >= max){
				printf("#");
			}
		}
		printf("\n");
		max --;
	}
return 0;
}
