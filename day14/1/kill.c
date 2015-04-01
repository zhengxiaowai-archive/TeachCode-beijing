#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void sig_handler(int sig)
{
	if(sig == SIGUSR1)
		printf("catch SINUSR1\n");
}


int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
	}
	else if(pid == 0)
	{
		if(signal(SIGUSR1, sig_handler) == SIG_ERR)
			perror("signal failed");
		printf("OK\n");
		while(1);
	}
	else
	{
		while(1)
		{	
			sleep(1);
			kill(pid, SIGUSR1);
		}
	}
	wait(NULL);
	return 0;
}
