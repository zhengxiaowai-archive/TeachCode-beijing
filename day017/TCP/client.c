#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *recv_pthread(void *arg)
{
	char buf[1024];
	int sk = *(int *)arg;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		int rc = recv(sk, buf, sizeof(buf), 0);
		if(rc > 0)
		{
			printf("%s", buf);
		}
	}
	return NULL;
}

void *send_pthread(void *arg)
{
	char buf[1024];
	int sk = *(int *)arg;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(STDIN_FILENO, buf, sizeof(buf));
		send(sk, buf, sizeof(buf), 0);

	}
	return NULL;
}
int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return -1;
	}
	int port = atoi(argv[2]);

	
	int sk = socket(AF_INET, SOCK_STREAM, 0);
	if(sk < 0)
	{
		perror("socket failed:");
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	int ct = connect(sk, (struct sockaddr *)&addr, sizeof(addr));
	if (ct < 0)
	{
		perror("connect failed:");
		return -1;
	}

	pthread_t thrd1, thrd2;
	pthread_create(&thrd1, NULL, recv_pthread, &sk);
	pthread_create(&thrd2, NULL, send_pthread, &sk);
	pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);
	
	close(sk);
	return 0;
}



















