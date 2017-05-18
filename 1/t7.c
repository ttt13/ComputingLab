#include <stdio.h>

int main( void )
{
	int i = 0;
	int n = 0;
	char hashtag = '#';
	int result = 0;

	while ( result = scanf("%d", &i) != EOF )
	{
		for (n = 0; n < i; n++)
		{
			printf("%c", hashtag);
		}
	printf("\n");
	}
	return 0;
}
