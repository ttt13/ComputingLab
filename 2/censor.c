#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	char c;
	char temp[128];
	int i = 0;
	int x = 1;
	int result = 1;

	/*for (int i = 1; i < argc; i++){
		printf("%s\n", argv[i]); */ // for arguments.

	while (c != EOF){
		c = getchar();

		if( (c == 39) || ( (c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')) ){
			temp[i] = c;
			i++;
		}
		temp[i]='\0';

		/* while(x < argc){
			result = strcmp(temp, argv[x]);// strlen(argv[x]));
			if (result != 0){
				x++;
			}
			if(result == 0){
				printf("CENSORED");
			}
		} */

		if ( (c != 39) && ( (c < 'a' || c > 'z' ) && (c < 'A' || c > 'Z')) ){
			while(x < argc && result != 0){
				result = strcmp(temp, argv[x]);// strlen(argv[x]));
				if (result != 0){
					x++;
				}
				if(result == 0){
					printf("CENSORED");
			}
		}
			if (result != 0){
				printf("%s", temp);
			}

			result = 1;
			temp[0] = '\0';
			x = 1;
			i = 0;
			printf("%c", c);
		}


		//if ( (c != 39) && ( (c < 65 || c > 90 ) && (c < 97 || c > 122)) ){
			
		
	}
		

return 0;
}

