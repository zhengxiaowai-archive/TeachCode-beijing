#include<stdio.h>
#define NDEBUG
#include <assert.h>//assert函数


int main(int argc, char *argv[])
{
	int a = 10;
	assert(a > 20);
	printf("%d\n",a);
	
	return 0;
}
