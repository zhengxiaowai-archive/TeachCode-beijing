#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd = open("1.txt", O_RDWR | O_CREAT | O_EXCL , 00664);
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