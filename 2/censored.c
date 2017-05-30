#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	char c; // for getchar()
	char temp[128];
	int i = 0; // index counter for temp string
	int x = 1; // counter for arguments
	int result = 1; // used for strcmp() != 0 to access the while loop below

	while ( (c = getchar()) != EOF){

		if( (c == 39) || ( (c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')) ){
			temp[i] = c;
			i++;
		}
		temp[i]='\0';

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
	}
return 0;
}

