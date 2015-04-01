#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
	printf("catch sigusr1\n");
}

int main(int argc, char *argv[])
{
	struct sigaction act;
	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(-1 == sigaction(SIGUSR1,&act,NULL))
		perror("sigactiom failed");

	while(1)
	{
		sleep(1);
		raise(SIGUSR1);
	}

	return 0;
}
