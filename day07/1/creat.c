#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	
	int fd = creat("1.txt", 00444);
	if(fd < 0)
	{
		printf("打开失败\n");
		return -1;
	}
	else
	{
		printf("%d\n", fd);
	}
	return 0;
}