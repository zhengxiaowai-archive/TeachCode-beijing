#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
static int sum(int value);
struct inout
{
	int value;
	int result;
};

int main(int argc, char *argv[])
{
	if( 2 != argc)
	{
		printf("参数错误\n");
		return -1;
	}

	struct inout *io = (struct inout *)malloc(sizeof(struct inout));
	if(NULL == io)
	{
		printf("内存分配失败\n");
		return -1;
	}
	
	io->value = *argv[1] - '0';
	//io->value = atoi(*argv[1]);
	io->result = sum(io->value);

	printf("输入的值是：%d, 计算的结果是: %d\n", io->value, io->result);

	return 0;
}

static int sum (int value)
{
	int result = 0 ;
	int i = 0;
	for(; i < value; ++i)
		result += i;
	return result;
}
