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

		if (c != 32 && c != 10 && c != '\''){
			charcount ++;
// c!= 37 || 61<c<91 || 96<c<123
		}
		if ( (c == 32 || c == 45 || c == 10) )
//&& (last == 46 || last == 44 || (64 < last < 91) || (96 < last < 123) ) ){
// (c != '\'' && (c == ' ' || c == '\n' || c == '-')){
		{
			if (last == 46 || last == 44 || 64 < last < 91 || 96 < last < 123 ){
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
