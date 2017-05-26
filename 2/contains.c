#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);

	char *str1 = argv[1];
	char *str2 = argv[2];

	if(len2 > len1)
	{
		printf("False\n");
		return 0;

	}else{
		for (int x = 0; x < (len1 - len2); x++)
		{
			int ret = strncmp(&str1[x], str2, len2);
				if (ret == 0);
				{
					printf("True\n");
					return 1;
				}
		}
	}
	printf("False\n");
	return 0;
}
