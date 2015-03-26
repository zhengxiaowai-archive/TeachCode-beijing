#include <stdio.h>
#include <string.h>

typedef struct people
{
	int id;
	char name[20];
}man;

int main(int argc, char *argv[])
{
	man m1;
	m1.id = 123456;
	strcpy(m1.name, "helloworld");
	FILE *fp = fopen("people.bin", "w+");
	fwrite(&m1, sizeof(man), 1, fp);

	fclose(fp);
	return 0;
	
}