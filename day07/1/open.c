#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("a.txt", O_RDWR | O_CREAT, 0664);
	if(fd < 0)
	{
		printf("open filed!\n");
		return -1;
	}
	else
	{
		printf("fd = %d\n", fd);
	}
	
	return 0;
}
