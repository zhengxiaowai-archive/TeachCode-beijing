#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp = fopen("a.txt", "w+");
	int ich;
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('d', fp);
	rewind(fp);
	while( (ich = fgetc(fp)) != EOF)
	{
		putchar(ich);
	}
	fputc('\n', stdout);
	fclose(fp);
	return 0;
	
}