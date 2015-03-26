#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd = open("1.txt", O_RDWR | O_CREAT , 00664);
	if(fd < 0)
	{
		printf("打开失败\n");
		return -1;
	}
	else
	{
		printf("%d\n", fd);
	}
	
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	read(fd, buf, sizeof(buf));
	printf("读到的内容是:\n%s\n", buf);
	close(fd);
	return 0;
}