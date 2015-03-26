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
	
	FILE *fp = fopen("people.bin", "r");
	
	fread(&m1, sizeof(man), 1, fp);
	printf("id = %d\n", m1.id);
	printf("name = %s\n", m1.name);
	
	fclose(fp);
	return 0;
}
	