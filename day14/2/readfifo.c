#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int fd = open("fifo",O_RDONLY);
	if(!fd)
	{
		perror("open failed:");
		return -1;
	}

	char buf[100];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		int len = read(fd, buf, sizeof(buf));
		if(len != 0)
		{
			printf("%s", buf);
		}
	}
	close(fd);
	return 0;
}