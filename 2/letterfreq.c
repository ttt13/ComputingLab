#include <stdio.h>

int main(void){
	int c;
	int alphabet[26];
	int temp = 0;
	int letterCount = 0;
	float freq = 0;
	int letter = 0;

	for (int x = 0; x < 26; x++){
		alphabet[x] = 0;
	}
	int x = 0;

	while (c != EOF){
		
		c = getchar();
		x = 0;
		temp = 'a';

		if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
			letterCount ++;
			//printf("%d\n", letterCount)
		;
		}
		while (c >= temp && temp >= 'a' && temp <= 'z'){
			if (c == temp){
				alphabet[x] ++;
				/* for (int derp=0; derp <26; derp++){
					printf("%d ", alphabet[derp]);
				} */
			}
				x ++;
				temp ++;

		}
		temp = 'A';
		while (c >= temp && temp >= 'A' && temp <= 'Z'){
			if (c == temp){
				alphabet[x] ++;
				/* for (int derp=0; derp <26; derp++){
					printf("%d ", alphabet[derp]); 
				} */
			}

				x ++;
				temp ++;

		}
	
	}
	letter = 'a';
	x = 0;
	while (letter >= 'a'&& letter <= 'z'){
		if (alphabet[x] != 0){
			freq = (float)alphabet[x] / (float)letterCount;
			printf("%c %.4f\n", letter, freq);

		}
	x++;
	letter++;
	}
	
	return 0;
}
