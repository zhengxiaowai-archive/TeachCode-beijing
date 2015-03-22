#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[6] = {0,1,2,4,5};
	/*插入一个元素*/
	int i;
	for(i = 5; i > 3; i--)
	{
		a[i] = a[i-1];
	}
	a[3] = 3;

	int j = 0;
	for(;j < 6; j++)
	{
		printf("%d ",a[j]);
	}

	printf("\n");
	/*012345*/
	/*删除一个元素*/
	int k;
	for(k=1; k < (6 - 2) + 1; k++)
	{
		a[k] = a[k+1];
	}

	j = 0;
	for(;j < 5; j++)
	{
		printf("%d ",a[j]);
	}
	
	printf("\n");

	return 0;
}
