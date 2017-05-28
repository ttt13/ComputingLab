#include <stdio.h>

int main(void)
{
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;

	char c;

	while (c != EOF)
	{
		c = getchar();

		if (c != ' ' && c != '\n' && c != '\''){
			charcount ++;
// c!= 37 || 61<c<91 || 96<c<123
		}
		if (c != '\'' && (c == ' ' || c == '\n' || c == '-')){
			wordcount++;
		}
		if (c != '\'' && c  == '\n'){
			linecount++;
		}

	}
	printf("%lu %lu %lu\n", charcount, wordcount, linecount);

return 0;
}
