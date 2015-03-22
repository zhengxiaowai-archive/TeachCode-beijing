#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
//a.txt不为空
int main(int argc, char *argv[])
{
	char buf[] = "hello world, hello world1234";

	int fd = open("a.txt", O_RDWR | O_CREAT, 00664);

	if(fd < 0)
	{
		printf("open failed\n");
		return -1;
	}

	char *addr = (char *)mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED , fd, 0);
	if(addr == (char *)-1)
	{
		printf("mmap failed\n");
		return -1;
	}
	
	memcpy(addr, buf, strlen(buf));

	munmap(addr, 1024);

	close(fd);

	return 0;
}