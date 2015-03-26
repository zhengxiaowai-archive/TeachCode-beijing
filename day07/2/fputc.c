#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp = fopen("a.txt", "w+");
	
	fputc('a', fp);
	fclose(fp);
	return 0;
	
}
