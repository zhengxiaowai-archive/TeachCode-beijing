#include <stdio.h>

int main(int argc, char *argv[])
{
	int *a[5];//默认初始化数组
	char b[] = {"sdfsdfsdfsdf"};//b[13]
	//a[0] ~ a[9]
	**a = 1;
	int **p;
	p = &a[0];
	//void *p2;//4个字节
	//char *p3;//指针的步数
	//p = &a[0]
	printf("%d\n",*a[0]);
	return 0;
}
