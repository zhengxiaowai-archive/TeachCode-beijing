#include <stdio.h>
#include <unistd.h>

#define LINEMAX 1024


int main(int argc, char *argv[])
{
	char line[LINEMAX] = {0};
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid < 0)
		perror("ford failed");
	else if(pid == 0)
	{
		sleep(1);
		close(fd[1]);
		read(fd[0], line, LINEMAX);
		printf("\nget:%s", line);
	}
	else
	{
		close(fd[0]);
		int w = write(fd[1], "hello world\n", 12);
	}

	return 0;
}
