#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		return -1;
	}
	int port = atoi(argv[1]);

	int sokt = socket(AF_INET, SOCK_DGRAM, 0);
	if (sokt < 0)
	{
		perror("socket failed");
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sokt, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		perror("bind failed");
		return -1;
	}

	char buf[1024];
	struct sockaddr_in client_addr;
	socklen_t  len = sizeof(client_addr);
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		memset(&client_addr, 0, sizeof(client_addr));
		if(recvfrom(sokt, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &len) == -1)
		{
			perror("recvfrom failed");
			return -1;
		}
		else
		{
			printf("%s:%s\n",inet_ntoa(client_addr.sin_addr), buf);

		}
	}
	close(sokt);
	return 0;
}
