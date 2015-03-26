#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd = open("1.txt", O_RDWR);
	if(fd < 0)
	{
		printf("打开失败\n");
		return -1;
	}
	else
	{
		printf("%d\n", fd);
	}
	
	 char rbuf[1024];
	 char wbuf[] = "hello";
	 memset(rbuf, 0, sizeof(rbuf));
     read(fd, rbuf, sizeof(rbuf));
	 printf("--------读到的内容是--------:\n%s\n", rbuf);
	
	write(fd, wbuf, strlen(wbuf));
	memset(rbuf, 0, sizeof(rbuf));
	lseek(fd, 0, SEEK_SET);
	read(fd, rbuf, sizeof(rbuf));
	printf("----------再次读到的内容是-------:\n%s\n", rbuf);
	close(fd);
	return 0;
}