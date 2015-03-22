#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{

	char str[40] = "$@#$dfdfg658675";
	int i = 0;
	for(;i != strlen(str); i++)
	{
		if(isalnum(str[i]))
		{
			printf("%c",str[i]);
		}
	}
	printf("\n");
	return 0;
}
