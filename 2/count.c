#include <stdio.h>

int main(void)
{
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;

	char c;
	char last;

	last = c = getchar();
	if (c!= 32 && c!= 10 && c!= '\''){
		charcount++;
	}
	if ( c != '\'' && c == '\n'){
		linecount++;
	}

	while (c != EOF)
	{
		c = getchar();

		if (c != EOF || c != '\''){
			charcount ++;
		}
		if  ( (c != 39) && ( (c < 65 || c > 90 ) && (c < 97 || c > 122)) )
		{
			if (((last > 64) && (last < 91)) || ((last > 96) && (last < 123))  ){
				//last == 46 || last == 44 (. ,)
				wordcount++;
			}
		}
		if (c != '\'' && c  == '\n'){
			linecount++;
		}
		last = c;
	}
	printf("%lu %lu %lu\n", charcount, wordcount, linecount);

return 0;
}
