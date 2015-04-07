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
	if(argc < 3)
	{
		return -1;
	}
	int port = atoi(argv[2]);

	int sockt = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockt < 0)
	{
		perror("socket failed");
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	char buf[1024];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		//scanf("%s", buf);
		read(STDIN_FILENO, buf, sizeof(buf));
		//printf("%s\n",buf);
		if(sendto(sockt, buf, strlen(buf), 0,(struct sockaddr *)&addr, sizeof(addr)) == -1)
		{
			perror("sendto failed");
			return -1;
		}
		
		//printf("%s\n",buf);
	}
	close(sockt);
	return 0;
}











