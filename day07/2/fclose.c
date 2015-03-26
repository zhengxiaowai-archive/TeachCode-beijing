#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp = fopen("a.txt", "w+");
	fclose(fp);
	return 0;
	
}
