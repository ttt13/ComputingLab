#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	if (argc < 3)
	{
		printf("false\n");
		return 0;
	}

	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);

	char *str1 = argv[1];
	char *str2 = argv[2];

	if(len2 > len1 || argc < 3)
	{
		printf("false\n");
		return 0;

	}else{
		for (int x = 0; x < (len1 - len2 + 1); x++)
		{
			int ret = strncmp(&str1[x], str2, len2);
			//printf("%d\n", ret);

			if (ret == 0){
				printf("true\n");
				return 0;
			}
		}
	printf("false\n");
	}
	return 0;
}
