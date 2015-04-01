#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int sig)
{
	//nothing to do
}



int mysleep(int s)
{
	if(SIG_ERR == signal(SIGALRM,sig_handler))
	{
		perror("signal failed");
	}

	alarm(s);
	pause();
	return (alarm(0));
}

int main(int argc, char *argv[])
{
	while(1)
	{
		mysleep(1);
		printf("i'm here\n");
	}

	return 0;
}
