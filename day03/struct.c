#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct student
{
	char name[20];
	int age;
}ST;

//malloc free
int main(int argc, char *argv[])
{
	ST *st1 = (ST *)malloc(sizeof(ST));
	st1->age = 20;//st1->age,->是指针访问
	strcpy(st1->name,"xiaomin");

	printf("%s\n",st1->name);
	printf("%d\n",st1->age);

	free(st1);
	return 0;
}
