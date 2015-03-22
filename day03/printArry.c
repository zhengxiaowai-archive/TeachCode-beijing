#include <stdio.h>


int main(int argc, char *argv[])
{
	int data[5] = {0,1,2,3,4};
	int length;
	/*循环输出*/
	for(length = 0; length < 5; length++)
	{
		printf("%d ",data[length]);
	}

	printf("\n");
	return 0;
}
