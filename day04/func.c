#include <stdio.h>

void print(int x)
{
	printf("hello  %d\n",x);
}

int main(int argc, char *argv[])
{
	int a = 10;
	print(a);//x = a
	return 0;
}
