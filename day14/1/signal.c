#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig)
{
	if(sig == SIGINT)
		printf("\ncatch SIGINT\n");
}


int main(int argc, char *argv[])
{
	
	signal(SIGINT,sigint_handler);
	while(1)
	{
		printf("test\n");
		sleep(1);
	}

	return 0;
}
