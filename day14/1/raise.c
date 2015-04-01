#include <stdio.h>
#include <signal.h>


void sig_handler(int sig)
{
	if(sig == SIGUSR1)
		printf("catch SIGUSR1\n");
}

int main(int argc, char *argv[])
{

	if(SIG_ERR == signal(SIGUSR1,sig_handler))
		perror("signal failed");


	while(1)
	{
		sleep(1);
		raise(SIGUSR1);
	}

	return 0;

}

