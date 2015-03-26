#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	if( argc != 2)
	{
		return -1;
	}
	
	int fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		printf("打开失败\n");
		return -1;
	}
	int fst = fcntl(fd, F_GETFL, 0); 
	if(fst < 0)
	{
		printf("获取文件信息失败\n");
		return -1;
	}
	
	switch(fst & O_ACCMODE)
	{
		case O_RDONLY:
			printf("RDONLY!\n");
			break;
		case O_WRONLY:
			printf("WDONLY!\n");
			break;
		case O_RDWR:
			printf("RDWR!\n");
			break;
		default:
			printf("unkonwn access mode\n");
			break;
	}
	
	
	return 0;
}