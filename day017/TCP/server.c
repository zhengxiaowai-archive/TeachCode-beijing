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
	if (argc < 2)
	{
		return -1;
	}
	int port = atoi(argv[1]);
	
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0)
	{
		perror("socket failed:");
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int bd = bind(sd,(struct sockaddr *) &addr, sizeof(addr));
	if(bd < 0)
	{
		perror("bind fialed:");
		return -1;
	}

	int ls = listen(sd, 5);
	if(ls < 0)
	{
		perror("listen failed:");
		return -1;
	}

	int sd_client = 0;
	struct sockaddr_in addr_client;
	memset(&addr_client, 0, sizeof(addr_client));
	socklen_t client_len = sizeof(addr_client);
	
	pthread_t thrd1, thrd2;
	while(1)
	{
		sd_client = accept(sd, (struct sockaddr *)&addr_client, &client_len);	
		if(sd_client < 0)
		{
			perror("accept failed:");
			return -1;
		}	
		printf("IP: %s\n",inet_ntoa(addr_client.sin_addr));
		pthread_create(&thrd1, NULL, recv_pthread, &sd_client);
		pthread_create(&thrd2, NULL, send_pthread, &sd_client);
	}
		


	close(sd);
	return 0;
}











