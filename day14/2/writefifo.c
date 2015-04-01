#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int fd = open("fifo",O_WRONLY);
	if(!fd)
	{
		perror("open failed:");
		return -1;
	}

	char buf[100];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(STDIN_FILENO, buf, sizeof(buf));
		write(fd, buf, strlen(buf));
	}
	close(fd);
	return 0;
}