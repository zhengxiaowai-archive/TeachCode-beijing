#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	FILE *fp = fopen("passwd", "r");
	char s[128] = { 0 };
	while(NULL != fgets(s, sizeof(s), fp))
	{
		printf("%s", s);
		memset(s, 0, sizeof(s));
	}
	fclose(fp);
	return 0;
	
}